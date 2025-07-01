#include "compiler.h"
#include "helpers/vector.h"
#include <assert.h>

struct compile_process *compile_process_create(const char *filename, const char *filename_out, int flags)
{
    FILE *file = fopen(filename, "r");

    if (!file)
        return NULL;

    FILE *out_file = NULL;
    if (filename_out)
    {
        out_file = fopen(filename_out, "w");
        if (!out_file)
            return NULL;
    }

    struct compile_process *process = calloc(1, sizeof(struct compile_process));
    if (!process)
        fclose(file);
    assert(process);

    process->node_vec = vector_create(sizeof(struct node *));
    process->node_tree_vec = vector_create(sizeof(struct node *));

    if (!process->node_vec || !process->node_tree_vec)
    {
        fclose(file);
        free(process);

        fprintf(stderr, "node_vec ou node_tree_vec não alocados corretamente");
        abort();
    }

    process->flags = flags;
    process->cfile.fp = file;
    process->ofile = out_file;

    return process;
}

void compile_process_free(struct compile_process *process)
{
    vector_free(process->node_vec);
    vector_free(process->node_tree_vec);
    fclose(process->cfile.fp);
    free(process);
}

// Pega um caracter do arquivo e atualiza a posicao.
char compile_process_next_char(struct lex_process *lex_process)
{
    struct compile_process *compiler = lex_process->compiler;
    compiler->pos.col += 1; // Atualiza a posicao da coluna.
    char c = getc(compiler->cfile.fp);
    if (c == '\n')
    {
        compiler->pos.line += 1;
        compiler->pos.col = 1;
    }

    return c;
}

// Apenas pega um caracter do arquivo.
char compile_process_peek_char(struct lex_process *lex_process)
{
    struct compile_process *compiler = lex_process->compiler;
    char c = getc(compiler->cfile.fp);
    ungetc(c, compiler->cfile.fp);

    return c;
}

// Adicionar um caracter no arquivo.
void compile_process_push_char(struct lex_process *lex_process, char c)
{
    struct compile_process *compiler = lex_process->compiler;
    ungetc(c, compiler->cfile.fp);
}
