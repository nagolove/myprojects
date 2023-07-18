#!/usr/bin/env lua5.4

local urls = {}
for line in io.open(string.format("%s/Downloads/audio-elements.html", os.getenv("HOME")), "r"):lines() do
    --print(line)
    local url = string.match(line, '<audio.*href.*=.*"(.*)".*/audio')
    if url then
        --print(url)
        table.insert(urls, url)
    end
end

for _, url in ipairs(urls) do
    local cmd = 'wget "' .. url .. '"'
    print(cmd)
    os.execute(cmd)
end
