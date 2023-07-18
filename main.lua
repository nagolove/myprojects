local gr = love.graphics
local font = gr.newFont("DejaVuSansMono.ttf", 20)
local coltext = gr.newText(font)
local u8 = require "utf8"
local inspect = require "inspect"

function love.draw()
end

-- Заполняет текстовый объект предварительно его очищая данным текстом
-- линейно интерполируя цвета от fromcolor до tocolor для каждого символа.
local function makeDescentColorText(textobj, textstr, fromcolor, tocolor)
    print("textobj", textobj, textstr, fromcolor, tocolor)
    for p, c in u8.codes(textstr) do
        print("p, c", p, c)
    end
end

function love.update(dt)
    local cx, cy = gr.getDimensions()
    cx, cy = cx / 2, cy / 2
    local s = "hippopotamus"
    --[[
    coltext:add(
        {
            {0.9, 0, 0, 1},
            "G",
        }, 
        cx, cy
    )
    --]]
end

function love.keypressed(_, key)
    if key == "space" then
        makeDescentColorText(
                coltext, "hippopotamus",
                {1, 0, 0, 1}, {0.5, 0, 0, 1}
            )
    end
end
