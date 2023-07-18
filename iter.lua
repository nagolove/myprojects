
local arr = {1, 2, 3, 100, 101, 0, 5}

local function even(a)
    local i = 1
    local len = #a
    return function()
        while i <= len do
            i = i + 1
            if a[i - 1] % 2 == 0 then
                return a[i - 1]
            end
        end
    end
end

for e in even(arr) do
    print(e)
end

local function ripairs(t)
    local i = #arr + 1
    return function()
        while i - 1 > 0 do
            i = i - 1
            return i, t[i]
        end
    end
end

print("---- ripairs ----")
arr = {1, 2, 3, 4, 5}
for k, v in ripairs(arr) do
    print(k, v)
end
