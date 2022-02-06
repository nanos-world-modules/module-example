#include "lua.h"
#include "lauxlib.h"

#ifndef LUAEXAMPLE_API
#define LUAEXAMPLE_API
#endif

LUAEXAMPLE_API int luaopen_example (lua_State *L);

static int test (lua_State *L) {
    lua_pushliteral (L, "Hello World");
    
	return 1;
}

LUAEXAMPLE_API int luaopen_example (lua_State *L) { 
	struct luaL_Reg functions[] = {
		{"test", test},
		{NULL, NULL},
	};

	luaL_newlib(L, functions);

	return 1;
}
