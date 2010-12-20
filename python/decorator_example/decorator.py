class decorator:

   def __init__(self,func,*args,**kw):
       self.__func = func
       print('calling decorator constructor')
       print(args)
       print(kw)

   def __call__(self,*args,**kw):
       print('inside decorator call !!!')
       print(args)
       print(kw)

       print('before calling method foo!!')
       self.__func(self,*args,**kw)
       print('after calling method foo!!')

class bar:

   @decorator
   def foo(self,param1,param2):
       print('executing method foo !!')
       print(param1)
       print(param2)
       print('finished executing foo !!!')

if __name__ == '__main__':

   b = bar()
   b.foo('test', 777)

