// Needed includes to reference the Lua SDK
extern "C" {
    #include "lua.h"
    #include "lauxlib.h"
}

// Definition of your custom functions
int test(lua_State *L) {
    // This will push 'Hello World' into the stack
    // Which can be obtained as the returning value from Lua
    lua_pushliteral(L, "Hello World");

    // Amount of values returned
    // (lua will get our string in the stack and pass as a return value)
    return 1;
}

// Definition of your custom library
extern "C" int luaopen_example (lua_State *L) { 
    // List of all custom functions
    struct luaL_Reg functions[] = {
        {"test", test},
        {NULL, NULL},
    };

    // Creates the library with the functions array
    luaL_newlib(L, functions);

    return 1;
}