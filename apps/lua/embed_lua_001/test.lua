local old_print = print
print = function(...)
  new_print(...);
end

a = 12;

print('Test Lua Script');
print('Test number from C function = ', testMul2Pi(a), ' = ', a, ' * 3.1415926');
print("Test string from C function = ", testString());

function testLuaFunc()
  print("Lua function called");
end

b = 34;

function printB()
  print('b = ', b);
end

function testGetFromLua()
  return b;
end

function testSetInLua(new_b)
  b = new_b
end

-- http://ilovelua.narod.ru/about_lua.html#Methods
lamp = {
  on = 0;
}
function lamp:Off()
  self.on = 0;
end

function lamp:On()
  self.on = 1;
end

lamp_1 = {
}

setmetatable(lamp_1, {__index = lamp});
lamp_1:On();

print('lamp ', lamp_1.on);

