#include <coroutine>

struct Context {
    bool mainloop;
};


void tile(struct Context *ctx) {
    //co_await
   
    // инициализация перемещения
    co_yield 

    // рисования анимации движения
    for (;;) {
        co_yield 
    }

    // конечная часть анимации движения
    for (;;) {
        co_yield 
    }
}

int main() {
    Context ctx;
    ctx.mainloop = true;
    while (ctx.mainloop) {
        // do step
        tile(&ctx);
    }
}
