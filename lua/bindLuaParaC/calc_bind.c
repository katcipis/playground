#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "calc_bind.h"

#define MOD_NAME "calc"
static lua_State* L = NULL;

struct _Calc {
    int ref;
};

void stack_dump(lua_State *L)
{
    int i = 1;
    int top = lua_gettop(L);
    printf("stack(%d): ", top);
    for (; i <= top; i++) {
        int t = lua_type(L, i);
        switch (t) {
        case LUA_TSTRING:
            printf("'%s'", lua_tostring(L, i));
            break;
        case LUA_TBOOLEAN:
            printf(lua_toboolean(L, i) ? "true" : "false");
            break;
        case LUA_TNUMBER:
            printf("%g", lua_tonumber(L, i));
            break;
        default:
            printf("%s", lua_typename(L, t));
        }
        printf(" ");
    }
    printf("\n");
}

static int calc_init()
{
    L = luaL_newstate();
    if (!L) {
        printf("Error alocating a lua_State !!!\n");
        return 0;
    }

    /* lets do a require "calc" */
    luaL_openlibs(L);

    lua_getglobal(L, "require");

    /* check if require exists */
    if (lua_isnil(L, -1)) {
        printf("Error, unable to find function require on global env !!!\n");
        lua_pop(L, 1);
        return 0;
    }

    lua_pushstring (L, MOD_NAME);
    lua_call(L, 1, 0); /* ignore the return, calc will be put on the global env */

    return 1;
}

static int operate(Calc *c, char* name) 
{
    int result;

    printf("calc reference: %i\n", c->ref);
    lua_rawgeti(L, LUA_REGISTRYINDEX, c->ref);

    /* check if calc is nil */
    if (lua_isnil(L, -1)) {
        printf("Error, calc object reference[%d] not found !!!\n", c->ref);
        lua_pop(L, 1);
        return 0;
    }

    /* call calc:name() / calc.name(calc)*/
    lua_getfield(L, 1, name);

    /* check if calc.name is nil */
    if (lua_isnil(L, -1)) {
        printf("Error, method[%s] not found !!!\n", name);
        lua_pop(L, 2);
        return 0;
    }

    lua_pushvalue(L, 1);
    lua_call(L, 1, 1);

    /* pops the result */
    result = lua_tointeger(L, 2);

    /* pops the return param and calc obj */
    lua_pop(L, 2);
    return result;
}

void calc_destroy(Calc *calculator)
{
    free(calculator);
}

Calc* calc_new(int a, int b) {
    int reference;
    Calc *calculator = malloc(sizeof(Calc));
 
    if (!L) {
        if (!calc_init()) {
            printf("Error initializing lua internal data !!!\n");
            return NULL;
        }
    }  

    /* put calc module at stack */ 
    lua_getglobal(L, MOD_NAME);

    /* check if calc is nil */
    if (lua_isnil(L, -1)) {
        printf("Error, unable to find calc module !!!\n");
        lua_pop(L, 1);
        return NULL;
    }

    lua_getfield(L, -1, "new");

    /* check if calc.new is nil */
    if (lua_isnil(L, -1)) {
        printf("Error, unable to find function new on calc module !!!\n");
        lua_pop(L, 2);
        return NULL;
    }

    /* put arguments at stack */
    lua_pushinteger(L, a);
    lua_pushinteger(L, b);

    /* call calc.new(a, b) */
    lua_call(L, 2, 1);

    /* check if calc is nil */
    if (lua_isnil(L, -1)) {
        printf("Error, calc.new returned nil !!!\n");
        lua_pop(L, 1);
        return NULL;
    } 

    /* ref and already pops the userdata from stack */
    reference = luaL_ref(L, LUA_REGISTRYINDEX);
    printf("reference: %i\n", reference);
    calculator->ref = reference;

    /* pops the calc table from stack, leaving an empty stack */
    lua_pop(L, 1);

    return calculator;
}

int calc_sum(Calc *c) {
    return operate(c, "sum");
}

int calc_sub(Calc *c) {
    return operate(c, "sub");
}

int calc_mul(Calc *c) {
    return operate(c, "mul");
}

int calc_div(Calc *c) {
    return operate(c, "div");
}
