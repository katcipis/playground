#include <asm/system.h> 
#include <asm/uaccess.h> 

#include <linux/init.h>
#include <linux/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h> 
#include <linux/slab.h> 
#include <linux/fs.h> 
#include <linux/errno.h> 
#include <linux/types.h> 
#include <linux/proc_fs.h>
#include <linux/fcntl.h> 


#define LINUX
#define MAIOR 100

int tamanhoMax = 128;
char *fila;
int indiceInicio = 0, indiceFim = 0;

ssize_t pop(struct file *filp, char *buf, size_t count, loff_t *f_pos) 
{     
    if (indiceInicio != indiceFim)
    {
        copy_to_user(buf, &fila[indiceInicio++], 1);       
        if (indiceInicio == indiceFim)
        {
            indiceInicio = 0;           
			indiceFim = 0;
        }
        return 1;
    }    
    return 0;       
}

ssize_t push(struct file *filp, char *buf, size_t count, loff_t *f_pos) 
{	int i = 0;

	if ( count/sizeof(char) > tamanhoMax - indiceFim){

		char * temp = kmalloc(tamanhoMax * 2, GFP_KERNEL);
		memcpy(temp, fila, tamanhoMax);
		kfree(fila);
		fila = temp;
		tamanhoMax = tamanhoMax * 2;
		return push(filp, buf, count, f_pos);
	}

    while (count > 0)
    {
        copy_from_user( &fila[indiceFim++], buf+i, 1);    
        --count;
        i++;   
    }
 
    return i;
}

struct file_operations fops = 
{
  read: pop,
  write: push
};

int init_module(void) 
{
  int retorno;
  retorno = register_chrdev(MAIOR, "memory", &fops);
  if (retorno < 0) 
    return retorno;
  fila = kmalloc(tamanhoMax, GFP_KERNEL);
  if (!fila) 
    return -ENOMEM;  
  memset(fila, 0, tamanhoMax);
  return 0;
}

void cleanup_module(void) 
{
      unregister_chrdev(MAIOR, "memory");
      if (fila) 
          kfree(fila);
}

