#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

static void cmd_help(char *arg);
static void cmd_push(char *arg);
static void cmd_print(char *arg);
static void cmd_exit(char *arg);
static void cmd_len(char *arg);
static void cmd_clear(char *arg);
static void cmd_resize(char *arg);

struct {
    char *cmd_name, *desc;
    void (*f)(char *arg);
} commands[] = {
    {
        "help",
        "help - this message",
        cmd_help
    },
    {
        "push",
        "push [num1 num2 num3] - push values to buffer",
        cmd_push
    },
    {
        "print",
        "print - print all values in buffer",
        cmd_print
    },
    {
        "exit",
        "exit - exit to shell",
        cmd_exit
    },
    {
        "len",
        "len - print buffer size and capacity",
        cmd_len
    },
    {
        "clear",
        "clear buffer",
        cmd_clear,
    },
    {
        "resize",
        "resize buffer capacity",
        cmd_resize,
    },
};
int commands_num = sizeof(commands) / sizeof(commands[0]);

struct CIRC {
    int *states;
    int cap, size, i, j;
};

struct CIRC circ = {};

void CIRC_init(struct CIRC *c, int cap) {
    assert(c);
    assert(cap > 0);
    memset(c, 0, sizeof(*c));
    c->cap = cap;
    c->states = calloc(c->cap, sizeof(c->states[0]));
}

void CIRC_shutdown(struct CIRC *c) {
    assert(c);
    if (c->states)
        free(c->states);
    memset(c, 0, sizeof(*c));
}

void CIRC_push(struct CIRC *c, int value) {
    /*printf("CIRC_push: value %d\n", value);*/
    c->states[c->i] = value;
    c->i = (c->i + 1) % c->cap;
    if (c->size < c->cap)
        c->size++;
}

void CIRC_clear(struct CIRC *c) {
    c->cap = 0;
    c->i = c->j = 0;
    c->size = 0;
}

void CIRC_resize(struct CIRC *c, int new_cap) {
    assert(c);
    if (new_cap != c->cap) {
        c->cap = new_cap;
        c->states = realloc(c->states, sizeof(c->states[0]) * c->cap);
        if (new_cap < c->size) {
            c->size = new_cap;
        }
    }
}

void CIRC_each(struct CIRC *c, void (*iter)(int value)) {
    int num = 0;
    for (int i = c->i; i < c->cap; i++) {
        if (num == c->size)
            return;
        num++;
        iter(c->states[i]);
    }
    for (int i = c->j; i < c->i; i++) {
        if (num == c->size)
            return;
        num++;
        iter(c->states[i]);
    }
}

static void cmd_resize(char *arg) {
    int new_cap = -1;
    if (sscanf("%d", arg, &new_cap) == 1)
        CIRC_resize(&circ, new_cap);
}

static void cmd_clear(char *arg) {
    CIRC_clear(&circ);
}

static void cmd_help(char *arg) {
    printf("commands:\n");
    for (int i = 0; i < commands_num; ++i) {
        printf("%s", commands[i].desc);
    }
}

static void cmd_len(char *arg) {
    printf("size %d\n", circ.size);
    printf("cap %d\n", circ.cap);
    printf("i %d, j %d\n", circ.i, circ.j);
}

static void cmd_push(char *arg) {
    char *tok = strtok(arg, " ");
    arg += strlen(tok);
    /*printf("cmd_push: tok '%s'\n", tok);*/
    while (tok) {
        int value = 0;
        if (sscanf(tok, "%d", &value) != 1) {
            printf("cmd_push: bad argument '%s'\n", tok);
            break;
        }
        CIRC_push(&circ, value);
        tok = strtok(NULL, " ");
    }
}

static void iter_print(int v) {
    printf("%d ", v);
}

static void cmd_print(char *arg) {
    CIRC_each(&circ, iter_print);
    printf("\n");
}

static void cmd_exit(char *arg) {
    exit(EXIT_SUCCESS);
}


int main() {
    char inp[64] = {};

    CIRC_init(&circ, 10);
    printf("try print \"help\" and press return\n");
    do {
        fgets(inp, sizeof(inp), stdin);
        char cmd[64] = {};
        sscanf(inp, "%63s", cmd);
        char *remain = inp + strlen(cmd);

        for (int i = 0; i < commands_num; ++i) {
            if (!strcmp(cmd, commands[i].cmd_name)) {
                commands[i].f(remain);
                continue;
            }
        }

    } while (strlen(inp) != 1);

    CIRC_shutdown(&circ);
}
