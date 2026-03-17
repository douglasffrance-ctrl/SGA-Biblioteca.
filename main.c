#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constantes
#define MAX_LIVROS 100
#define MAX_USUARIOS 100
#define MAX_EMPRESTIMOS 100

// Definições de Estruturas
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int codigo;
    char titulo[101];
    char autor[81];
    char editora[61];
    int ano_publicado;
    int num_exemplares_disponives;
    int status; // 1: Ativo, 0: Inativo
} Livro;

typedef struct{
    int matricula;
    char nome_completo[101];
    char curso[51];
    char telefone[16];
    Data data_cadastro;
    int status;
} Usuario;

typedef struct{
    int codigo_emprestimo;
    int matricula_usuario;
    int codigo_livro;
    Data data_emprestimo;
    Data data_prevista_devolucao;
    int status; // 1: Ativo/Emprestado, 0: Devolvido
} Emprestimo;

 typedef struct{
  int codigo_livro;
  int contagem;
 }ContadorLivro;

// Estruturas Globais
Livro livros[MAX_LIVROS];
Usuario usuarios[MAX_USUARIOS];
Emprestimo emprestimos[MAX_EMPRESTIMOS];
ContadorLivro contadores [MAX_LIVROS];

// Contadores Globais
int total_livros = 0;
int total_usuarios = 0;
int total_emprestimos = 0;
int total_contadores = 0;


// Protótipos das Funções

// Funções de Menu
void exibir_menu_principal();
void menu_usuarios();
void menu_livros();
void menu_emprestimos();
void menu_relatorios();

// Funções Modulares (IMPLEMENTADAS OU STUBS)
void inicializar_estruturas();
void limpar_buffer();
void cadastrar_livros();
void cadastrar_usuario();
void realizar_emprestimo();
void realizar_devolucao();
void pesquisar_livro();
void pesquisar_usuario();
void pesquisar_emprestimos_ativos();
void listar_livros();
void listar_usuarios();
void carregar_dados();
void salvar_dados_em_arquivos();
void implementar_backup();
void relatorio_usuarios_em_atraso();
void relatorio_livros_mais_emprestados();
void funcao_busca_avancada();
void sistema_renovacao_emprestimos();


// --- Implementação do MAIN ---

int main() {
    int opcao;

    inicializar_estruturas();
    // carregar_dados(); // Descomentar ao implementar

    do {
        exibir_menu_principal();
        printf("Escolha uma opcao: ");

        // Leitura da opção e tratamento de erro
        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            opcao = -1; // Sinaliza opção inválida
        } else {
            limpar_buffer(); // Limpa o '\n' do buffer
        }

        if (opcao == -1) {
            printf("\nOpcao invalida (Nao numerica). Tente novamente.\n");
        }

        switch(opcao) {
            case 1:
                menu_livros();
                break;
            case 2:
                menu_usuarios();
                break;
            case 3:
                menu_emprestimos();
                break;
            case 4:
                menu_relatorios();
                break;
            case 0:
                printf("\nSaindo do sistema. Nao esqueca de salvar os dados!\n");
                // salvar_dados_em_arquivos(); // Implementar chamada de salvamento aqui
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}


// --- Implementação das Funções Auxiliares ---

void limpar_buffer(){
    int c;
    while ((c = getchar())!= '\n' &&
           c != EOF) {}
}


void inicializar_estruturas(){
    total_livros = 0;
    total_usuarios = 0;
    total_emprestimos = 0;
    printf("Sistema de biblioteca inicializado.\n");
}


// --- Implementação das Funções de Menu ---


void exibir_menu_principal(){
    printf("\n================================\n");
    printf(" MENU PRINCIPAL - SISTEMA BIBLIOTECA \n");
    printf("====================================\n");
    printf( "1. Gerenciar Livros\n");
    printf("2. Gerenciar Usuarios\n");
    printf("3. Gerenciar Emprestimos/Devolucoes\n");
    printf("4. Relatorios Avancados\n");
    printf("0. Sair\n");
    printf("------------------------------------\n");
}


void menu_livros(){
    int opcao;
    do{
        printf("\n----Menu Livros------\n");

        printf("1. Cadastrar Novo Livro\n");
        printf("2. Pesquisar Livro por Codigo/Titulo\n");
        printf("3. Listar Todos os Livros\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao:\n ");

        if(scanf("%d", &opcao) != 1){
            limpar_buffer();
            opcao = -1;
        } else{
            limpar_buffer();
        }

        switch(opcao){
            case 1:
                cadastrar_livros();
                break;
            case 2:
                pesquisar_livro();
                break;
            case 3:
                listar_livros();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break; // Adicionei break para não cair no default
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}

void menu_usuarios(){
    int opcao;
    do{
        printf("\n----Menu Usuarios------\n");

        printf("1. Cadastrar Novo Usuario\n");
        printf("2. Pesquisar Usuario por Matricula/Nome\n");
        printf("3. Listar Todos os Usuarios\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao:\n ");

        if(scanf("%d", &opcao) != 1){
            limpar_buffer();
            opcao = -1;
        } else{
            limpar_buffer();
        }

        switch(opcao){
            case 1:
                cadastrar_usuario();
                break;
            case 2:
                pesquisar_usuario();
                break;
            case 3:
                listar_usuarios();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break; // Adicionei break para não cair no default
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}

void menu_emprestimos(){
    int opcao;
    do{
        printf("\n----Menu Emprestimos & Devolucoes------\n");

        printf("1. Realizar Novo Emprestimo \n");
        printf("2. Realizar Devolucao\n");
        printf("3. Pesquisar Emprestimos Ativos\n");
        printf("4. Sistema de Renovacao de Emprestimos\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao:\n ");

        if(scanf("%d", &opcao) != 1){
            limpar_buffer();
            opcao = -1;
        } else{
            limpar_buffer();
        }

        switch(opcao){
            case 1:
                realizar_emprestimo();
                break;
            case 2:
                realizar_devolucao();
                break;
            case 3:
                pesquisar_emprestimos_ativos();
                break;
            case 4:
                sistema_renovacao_emprestimos();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break; // Adicionei break para não cair no default
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}

 void menu_relatorios(){
    int opcao;
    do{
        printf("\n----Menu Relatorios Avancados------\n");

        printf("1. Relatorio de Usuarios em Atraso\n");
        printf("2. Relatorio de Livros Mais Emprestados\n");
        printf("3. Funcao de Busca Avancada (Livros e Usuarios)\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao:\n ");

        if(scanf("%d", &opcao) != 1){
            limpar_buffer();
            opcao = -1;
        } else{
            limpar_buffer();
        }

        switch(opcao){
            case 1:
                relatorio_usuarios_em_atraso();
                break;
            case 2:
                relatorio_livros_mais_emprestados();
                break;
            case 3:
                funcao_busca_avancada();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break; // Adicionei break para não cair no default
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}


// --- Implementação das Funções Modulares (COM CORREÇÕES) ---

    void cadastrar_livros(){
    if(total_livros >= MAX_LIVROS){
        printf("\n ERRO. Limite maximo de livros (%d) atingido.\n", MAX_LIVROS);
        return;
    }

    int indice = total_livros;
    printf("\n--- Cadastrar Novo Livro ---\n");

    // Codigo é atribuído automaticamente (indice + 1)
    livros[indice].codigo = indice + 1;
    printf("Codigo do livro: (%d)\n",livros[indice].codigo);

    printf("Digite o titulo (max.100 caract):\n ");
    if(scanf("%100[^\n]", livros[indice].titulo) != 1) {
        printf("ERRO: Falha na leitura do titulo. Cadastro cancelado.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    printf("\nDigite o autor (max.80 caract):\n");
    if(scanf("%80[^\n]",livros[indice].autor) != 1) {
        printf("ERRO: Falha na leitura do Autor. Cadastro cancelado.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    printf("\nDigite a editora (max.60 caract):\n");
    if(scanf("%60[^\n]",livros[indice].editora) != 1) {
        printf("ERRO: Falha na leitura da editora. Cadastro cancelado.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    printf("Digite o ano da publicacao:");
    if (scanf("%d",&livros[indice].ano_publicado)!=1){
        printf("\n ERRO. Entrada de ano invalida. Cadastro cancelado.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    // CORREÇÃO: Adicionando a leitura de num_exemplares_disponives
    printf("Digite o numero de exemplares disponiveis:");
    if (scanf("%d", &livros[indice].num_exemplares_disponives) != 1 || livros[indice].num_exemplares_disponives < 0) {
        printf("\n ERRO. Entrada de exemplares invalida. Cadastro cancelado.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();


    livros[indice].status = 1; // 1: Ativo
    total_livros++;
    printf("\n Sucesso: Livro '%s' (codigo %d) cadastrado com sucesso!\n",livros[indice].titulo, livros[indice].codigo);
} // CORREÇÃO: Chave de fechamento da função cadastrar_livros adicionada aqui

 //FUNÇÕES AUXILIARES DE BUSCA

    int buscar_livro_por_codigo(int codigo) {
    // Percorre todos os livros cadastrados
    for (int i = 0; i < total_livros; i++) {
        if (livros[i].codigo == codigo) {
            return i; // Livro encontrado! Retorna o índice (posicao no vetor)
        }
    }
    return -1; // Livro não encontrado
}

void cadastrar_usuario(){
    if(total_usuarios >= MAX_USUARIOS){
        printf("\n ERRO. Limite maximo de usuarios (%d) atingido.\n", MAX_USUARIOS);
        return;
    }

    int indice = total_usuarios;
    printf("\n--- Cadastrar Novo Usuario ---\n");

    usuarios[indice].matricula = indice + 1;
    printf("Matricula do usuario: %d (automatico)\n",usuarios[indice].matricula);

    printf("Digite o nome completo (max.100 caract):\n ");
    if(scanf("%100[^\n]", usuarios[indice].nome_completo) != 1) {
        printf("ERRO: Falha na leitura do nome. Cadastro cancelado.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    printf("Digite o curso (max.50 caract): ");
    if(scanf("%50[^\n]", usuarios[indice].curso) != 1) {
        printf("ERRO: Falha na leitura do curso. Cadastro cancelado.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    printf("Digite o telefone (max.15 caract): ");
    if(scanf("%15[^\n]", usuarios[indice].telefone)!= 1){
        printf("ERRO: Falha ao digitar numero de telefone. Cadastro cancelado.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();


    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    usuarios[indice].data_cadastro.dia = tm.tm_mday;
    usuarios[indice].data_cadastro.mes = tm.tm_mon + 1;
    usuarios[indice].data_cadastro.ano = tm.tm_year + 1900;

    total_usuarios++;

    printf("\n Sucesso: Usuario '%s' (matricula %d) cadastrado com sucesso!\n",usuarios[indice].nome_completo, usuarios[indice].matricula);
    printf("Data de cadastro: %02d/%02d/%d\n",usuarios[indice].data_cadastro.dia, usuarios[indice].data_cadastro.mes, usuarios[indice].data_cadastro.ano);
}

  //FUNÇÕES AUXILIARES DE BUSCA

  int buscar_usuario_por_matricula(int matricula) {
    // Percorre todos os usuários cadastrados
    for (int i = 0; i < total_usuarios; i++) {
        if (usuarios[i].matricula == matricula) {
            return i; // Usuário encontrado! Retorna o índice
        }
    }
    return -1; // Usuário não encontrado
}
   void realizar_emprestimo(){
        int mat_usuario, cod_livro;
        int indice_usuario, indice_livro;


    if (total_emprestimos>= MAX_EMPRESTIMOS){
        printf("ERRO: Limiete maximo de emprestimos (%d) atingido.\n", MAX_EMPRESTIMOS);
        return;
    }
        printf("\n---- Realizar novo emprestimo-----\n");
        printf("Digite a MATRICULA do usuario: ");
           if (scanf("%d", &mat_usuario)!= 1){
            printf("Entrada invalida. Tente novamente.\n");
               limpar_buffer();
               return;
           }
           limpar_buffer();

           indice_usuario = buscar_usuario_por_matricula(mat_usuario);
            if (indice_usuario == -1){
                printf("ERRO: usuario com matricula (%d) nao encontrado.\n", mat_usuario);
                return;
            }
        printf("Digite o CODIGO do livro: ");
           if (scanf("%d", &cod_livro)!= 1){
            printf("Entrada invalida. Tente novamente.\n");
               limpar_buffer();
               return;
            }
          limpar_buffer();

           indice_livro = buscar_livro_por_codigo(cod_livro);
            if (indice_livro == -1){
                printf("ERRO: livro com codigo (%d) nao encontrado.\n", cod_livro);
                return;
            }
       //verificação de disponibilidade.
          if (livros[indice_livro].num_exemplares_disponives <= 0){
            printf("ERRO: livro \"%s\" nao possui exemplares disponives para emprestimo.\n", livros[indice_livro].titulo);
            return;
          }
        //obter o tempo atual em segundos .
          time_t tempo_atual = time(NULL);
          struct tm *tm_emprestimo = localtime(&tempo_atual);

        //calcular o tempo para devolução ( tempo atual + 7 dias em segundos)
        //7 dias* 24 horas* 60 mts* 60sgunds.
        time_t tempo_devolucao =  tempo_atual +(7 * 24 * 60 * 60);
         struct tm *tm_devolucao = localtime(&tempo_devolucao);

         Emprestimo *novo_emprestimo = &emprestimos[total_emprestimos];

         //atribuir valores
         novo_emprestimo -> codigo_emprestimo = total_emprestimos + 1;
         novo_emprestimo -> matricula_usuario = mat_usuario;
         novo_emprestimo -> codigo_livro = cod_livro;

         //data de emprestimo
         novo_emprestimo -> data_emprestimo.dia =tm_emprestimo ->tm_mday;
         novo_emprestimo -> data_emprestimo.mes =tm_emprestimo ->tm_mon + 1;
         novo_emprestimo -> data_emprestimo.ano =tm_emprestimo ->tm_year + 1900;

        //data prevista da devolução( 7 dias depois).
        novo_emprestimo -> data_prevista_devolucao.dia =tm_devolucao  ->tm_mday;
         novo_emprestimo -> data_prevista_devolucao.mes =tm_devolucao ->tm_mon + 1;
         novo_emprestimo -> data_prevista_devolucao.ano =tm_devolucao ->tm_year + 1900;

        novo_emprestimo -> status = 0;


        //atualizar disponibilidade do livro.
        livros[indice_livro].num_exemplares_disponives--;
        total_emprestimos++;

        printf("\n Emprestimo #%d realizado com sucesso!\n", novo_emprestimo->codigo_emprestimo);

         printf(" Livro: %s\n", livros[indice_livro].titulo);

        printf(" Devolucao Prevista: %02d/%02d/%d\n",novo_emprestimo->data_prevista_devolucao.dia,
        novo_emprestimo->data_prevista_devolucao.mes,
        novo_emprestimo->data_prevista_devolucao.ano);

     printf(" Exemplares restantes: %d\n", livros[indice_livro].num_exemplares_disponives);

    }
// Esta função auxiliar deve ser colocada junto com suas outras funções de busca

int buscar_emprestimo_por_codigo(int codigo) {
    // Percorre todos os empréstimos registrados
    for (int i = 0; i < total_emprestimos; i++) {
        if (emprestimos[i].codigo_emprestimo == codigo && emprestimos[i].status == 0) {
            return i; // Empréstimo ativo encontrado
        }
    }
    return -1; // Empréstimo não encontrado ou já devolvido
}
 void realizar_devolucao(){

    int cod_emprestimo;
    int indice_emprestimo, indice_livro;

    printf("\n------Realizar devolucao------\n");

    printf("Digite o codigo do emprestimo a ser devolvido: ");
       if(scanf("%d",&cod_emprestimo)!= 1){
        printf("Entrada invalida. Tente novamente.\n");
        limpar_buffer();
        return;
       }
    limpar_buffer();

    //uso da função auxiliar para encontra emprestimo ativo.
    indice_emprestimo = buscar_emprestimo_por_codigo(cod_emprestimo);
    if (indice_emprestimo == -1){
        printf("ERRO: emprestimo #%d nao encontrado ou ja foi devolvido.\n", cod_emprestimo);
        return;
    }
    //pegar codigo do livro do emprestimo encontrado.
    int cod_livro = emprestimos[indice_emprestimo].codigo_livro;

    //encontra livro para atualizar estoque.
    indice_livro = buscar_livro_por_codigo(cod_livro);
      if(indice_livro== -1){
        printf("ALERTA: livro associado ao emprestimo nao encontrado no catalogo.\n");
      } else{
          livros[indice_livro].num_exemplares_disponives++;
          }

      //atualizar status do emprestimo.
      emprestimos[indice_emprestimo].status = 1; //devolvido.

       printf("\n Devolucao do emprestimo #%d concluida com sucesso!\n", cod_emprestimo);
     if(indice_livro != -1){
        printf(" livro \"%s\" devolvido.\n",livros[indice_livro].titulo);
        printf("exemplares disponives agora: %d\n",livros[indice_livro].num_exemplares_disponives);
     }

 }


   void pesquisar_livro() {

    int codigo;
    int indice;
    int status;

    printf("\n------Pesquisar livro por codigo------\n");

    printf("Digite o codigo do livro para pesquisar: ");
       if(scanf("%d",&codigo)!= 1){
        printf("Entrada invalida. Tente novamente.\n");
        limpar_buffer();
        return;
       }
    limpar_buffer();

    //uso da função auxiliar de buscar livro.
    indice = buscar_livro_por_codigo(codigo);
    if (indice == -1){
        printf("ERRO: livro com codigo #%d nao encontrado no catalogo.\n", codigo);
    } else{
    Livro l = livros[indice];
        printf("\n livro encontrado:\n");

       printf("- Codigo: %d\n", l.codigo);
        printf("- Titulo: %s\n", l.titulo);
        printf("- Autor: %s\n", l.autor);
        printf("- Editora: %s\n", l.editora);
        printf("- Ano de Publicacao: %d\n", l.ano_publicado);

        // exibe status e disponibilidade.
        printf("- Status: %s\n", (l.status == 1 ? "Ativo" : "Inativo/Arquivado"));
        printf("- Exemplares Disponiveis: %d\n", l.num_exemplares_disponives);
         }

       }

void pesquisar_usuario() {

    int matricula;
    int indice;
    int status;

    printf("\n------ Pesquisar Usuario por Matricula ------\n");

    printf("Digite a matricula do usuario para pesquisar: ");
    if(scanf("%d", &matricula) != 1){
        printf("Entrada invalida. Tente novamente.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    // Uso da função auxiliar de buscar matricula.
    indice = buscar_usuario_por_matricula(matricula);

    if (indice == -1){
        printf(" ERRO: Usuario com matricula %d nao encontrado no sistema.\n", matricula);
    } else { // BLOCO 'ELSE' CORRIGIDO E NECESSÁRIO
        Usuario u = usuarios[indice];

        printf("\n USUARIO ENCONTRADO:\n");

        printf("- Matricula: %d\n", u .matricula);
        printf("- Nome completo: %s\n", u.nome_completo);
        printf("- Telefone: %s\n", u .telefone);
        printf(" -Curso: %s\n", u .curso);

      printf("- Status: %s\n", (u.status == 1 ? "Ativo" : "Inativo"));
    }
}
   void listar_livros(){

    printf("\n----- CATALOGO DE LIVROS CADASTRADOS -----\n");

    // Verificar se ha livros.
    if(total_livros == 0){
        printf("Nenhum livro cadastrado no sistema.\n");
        return;
    }

    // Imprime o cabeçalho da tabela
    printf("| %-6s | %-40s | %-20s | %-10s | %-10s |\n",
           "CODIGO", "TITULO", "AUTOR", "DISPON.", "STATUS");
    // Linha separadora ajustada (garantindo alinhamento)
    printf("|--------|------------------------------------------|----------------------|------------|------------|\n");

    // PERCORRE E EXIBE CADA LIVRO.
    for (int i = 0; i < total_livros; i++){
        Livro l = livros[i];

        const char* status_texto = (l.status == 1) ? "Ativo" : "Inativo";

        printf("| %-6d | %-40s | %-20s | %-10d | %-10s |\n",
               l.codigo,
               l.titulo,
               l.autor,
               l.num_exemplares_disponives,
               status_texto);
    }

    printf("--------------------------------------------------------------------------------------------------\n");
    printf("Total de livros cadastrados: %d\n", total_livros );
}

  void listar_usuarios(){

    printf("\n----- LISTA DE USUARIOS CADASTRADOS -----\n");

    // Verificar se ha USUARIOS.
    if(total_usuarios == 0){
        printf("Nenhum usuario cadastrado no sistema.\n");
        return;
    }

    // Imprime o cabeçalho da tabela
    printf("| %-10s | %-40s | %-15s | %-7s |\n",
           "MATRICULA", "NOME COMPLETO", "TELEFONE", "CURSO", "STATUS");
    // Linha separadora ajustada (garantindo alinhamento)
    printf("|--------|------------------------------------------|----------------------|------------|------------|\n");

    // PERCORRE E EXIBE CADA LIVRO.
    for (int i = 0; i < total_usuarios; i++){
        Usuario u = usuarios[i];

        const char* status_texto = (u.status == 1) ? "Ativo" : "Inativo";

        printf("| %-10d | %-40s | %-15s | %-7s|\n",
               u .matricula,
               u .nome_completo,
               u .telefone,
               u . curso,
               status_texto);
    }

    printf("--------------------------------------------------------------------------------------------------\n");
    printf("Total de usuarios cadastrados: %d\n", total_usuarios);
}

  void pesquisar_emprestimos_ativos(){
     int total_ativos = 0;
     printf("\n--------RELATORIO DE EMPRESTIMOS ATIVOS-------\n");

    // Imprime o cabeçalho da tabela
    printf("| %-10s | %-10s | %-10s | %-15s | %-15S |\n",
           "COD.EMPRESTIMO", "MATRICULA", "COD.LIVRO", "DATA EMPRESTIMO", "DEVOLUCAO PREV.");
    // Linha separadora ajustada (garantindo alinhamento)
    printf("|--------|------------------------------------------|----------------------|------------|------------|\n");

    // PERCORRE TODOS OS EMPRESTIMOS.
    for (int i = 0; i < total_emprestimos; i++){
        Emprestimo e = emprestimos[i];

         if (e.status == 0){
            total_ativos++;

       printf("| %-10d | %-10d | %-10d | %02d/%02d/%d | %02d/%02d/%d |\n",
                   e.codigo_emprestimo,
                   e.matricula_usuario,
                   e.codigo_livro,
                   e.data_emprestimo.dia,
                   e.data_emprestimo.mes,
                   e.data_emprestimo.ano,
                   e.data_prevista_devolucao.dia,
                   e.data_prevista_devolucao.mes,
                   e.data_prevista_devolucao.ano);
            }

        }

    printf("|--------|------------------------------------------|----------------------|------------|------------|\n");
       if (total_ativos == 0){
        printf("nenhum emprestimo ativo no momento.\n");
       } else{
        printf("Total de emprestimos ativos: %d\n",total_ativos);
    }
  }
   void carregar_dados() {
    FILE *arquivo;

    printf("\n------ CARREGANDO DADOS DO SISTEMA ------\n");

    //Carregar Livros
    arquivo = fopen("livros.dat", "rb");
    if (arquivo != NULL) {
        if (fread(&total_livros, sizeof(int), 1, arquivo) == 1) {

            fread(livros, sizeof(Livro), total_livros, arquivo);
        }
        fclose(arquivo);
        printf(" %d Livros carregados do arquivo 'livros.dat'.\n", total_livros);
    } else {
        total_livros = 0;
        printf(" Arquivo 'livros.dat' nao encontrado. Iniciando com 0 livros.\n");
    }

    //carregar Usuários
    arquivo = fopen("usuarios.dat", "rb");
    if (arquivo != NULL) {
        if (fread(&total_usuarios, sizeof(int), 1, arquivo) == 1) {
            fread(usuarios, sizeof(Usuario), total_usuarios, arquivo);
        }
        fclose(arquivo);
        printf(" %d Usuarios carregados do arquivo 'usuarios.dat'.\n", total_usuarios);
    } else {
        total_usuarios = 0;
        printf(" Arquivo 'usuarios.dat' nao encontrado. Iniciando com 0 usuarios.\n");
    }

    //Carregar Empréstimos
    arquivo = fopen("emprestimos.dat", "rb");
    if (arquivo != NULL) {
        if (fread(&total_emprestimos, sizeof(int), 1, arquivo) == 1) {
            fread(emprestimos, sizeof(Emprestimo), total_emprestimos, arquivo);
        }
        fclose(arquivo);
        printf("%d Emprestimos carregados do arquivo 'emprestimos.dat'.\n", total_emprestimos);
    } else {
        total_emprestimos = 0;
        printf("Arquivo 'emprestimos.dat' nao encontrado. Iniciando com 0 emprestimos.\n");
    }

    printf("---------------------------------------------\n");
}
   void salvar_dados_em_arquivos() {
    FILE *arquivo;

    // Salvar Livros
    arquivo = fopen("livros.dat", "wb");
    if (arquivo != NULL) {

        fwrite(&total_livros, sizeof(int), 1, arquivo);

        fwrite(livros, sizeof(Livro), total_livros, arquivo);
        fclose(arquivo);
        printf(" %d Livros salvos com sucesso em 'livros.dat'.\n", total_livros);
    } else {
        printf(" ERRO: Nao foi possivel abrir o arquivo 'livros.dat' para escrita.\n");
    }

    // Salvar Usuários
    arquivo = fopen("usuarios.dat", "wb");
    if (arquivo != NULL) {
        fwrite(&total_usuarios, sizeof(int), 1, arquivo);
        fwrite(usuarios, sizeof(Usuario), total_usuarios, arquivo);
        fclose(arquivo);
        printf(" %d Usuarios salvos com sucesso em 'usuarios.dat'.\n", total_usuarios);
    } else {
        printf(" ERRO: Nao foi possivel abrir o arquivo 'usuarios.dat' para escrita.\n");
    }

    //Salvar Empréstimos
    arquivo = fopen("emprestimos.dat", "wb");
    if (arquivo != NULL) {
        fwrite(&total_emprestimos, sizeof(int), 1, arquivo);
        fwrite(emprestimos, sizeof(Emprestimo), total_emprestimos, arquivo);
        fclose(arquivo);
        printf(" %d Emprestimos salvos com sucesso em 'emprestimos.dat'.\n", total_emprestimos);
    } else {
        printf(" ERRO: Nao foi possivel abrir o arquivo 'emprestimos.dat' para escrita.\n");
    }
}
    void implementar_backup() {
    FILE *arquivo;

    printf("\n------ INICIANDO BACKUP DE DADOS ------\n");

    //Backup Livros
    arquivo = fopen("livros_backup.dat", "wb");
    if (arquivo != NULL) {
        fwrite(&total_livros, sizeof(int), 1, arquivo);
        fwrite(livros, sizeof(Livro), total_livros, arquivo);
        fclose(arquivo);
        printf(" Backup de livros criado em 'livros_backup.dat'.\n");
    }

    //Backup Usuários
    arquivo = fopen("usuarios_backup.dat", "wb");
    if (arquivo != NULL) {
        fwrite(&total_usuarios, sizeof(int), 1, arquivo);
        fwrite(usuarios, sizeof(Usuario), total_usuarios, arquivo);
        fclose(arquivo);
        printf(" Backup de usuarios criado em 'usuarios_backup.dat'.\n");
    }

    //Backup Empréstimos
    arquivo = fopen("emprestimos_backup.dat", "wb");
    if (arquivo != NULL) {
        fwrite(&total_emprestimos, sizeof(int), 1, arquivo);
        fwrite(emprestimos, sizeof(Emprestimo), total_emprestimos, arquivo);
        fclose(arquivo);
        printf(" Backup de emprestimos criado em 'emprestimos_backup.dat'.\n");
    }

    printf("------ BACKUP CONCLUIDO ------\n");
}
       // função auxiliar
   int comparar_datas(Data d1, Data d2) {
   // Anos iguais
    if (d1.ano < d2.ano) return 1;
    if (d1.ano > d2.ano) return -1;

       // Meses iguais
    if (d1.mes < d2.mes) return 1;
    if (d1.mes > d2.mes) return -1;

    // Datas iguais
    if (d1.dia < d2.dia) return 1;
    if (d1.dia > d2.dia) return -1;

    return 0;
}

   void relatorio_usuarios_em_atraso() {
    Data data_atual;
    int total_atrasos = 0;

    printf("\n------ RELATORIO DE EMPRESTIMOS EM ATRASO ------\n");

    // Pede a data atual
    printf("Digite a data de HOJE (dd mm aaaa) para comparacao: ");
    if (scanf("%d %d %d", &data_atual.dia, &data_atual.mes, &data_atual.ano) != 3) {
        printf("Entrada de data invalida.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    printf("| %-10s | %-40s | %-15s | %-15s |\n",
           "MATRICULA", "NOME DO USUARIO", "COD. LIVRO", "DEVOL. PREV.");
    printf("|------------|------------------------------------------|-----------------|-----------------|\n");

    for (int i = 0; i < total_emprestimos; i++) {
        Emprestimo e = emprestimos[i];

        if (e.status == 0 && comparar_datas(e.data_prevista_devolucao, data_atual) == 1) {
            total_atrasos++;

            // Busca o nome do usuário para o relatório
            int indice_usuario = buscar_usuario_por_matricula(e.matricula_usuario);
            const char* nome_usuario = (indice_usuario != -1) ? usuarios[indice_usuario].nome_completo : "USUARIO DESCONHECIDO";

            printf("| %-10d | %-40s | %-15d | %02d/%02d/%d    |\n",
                   e.matricula_usuario,
                   nome_usuario,
                   e.codigo_livro,
                   e.data_prevista_devolucao.dia,
                   e.data_prevista_devolucao.mes,
                   e.data_prevista_devolucao.ano);
        }
    }

    printf("--------------------------------------------------------------------------------------------------\n");
    if (total_atrasos == 0) {
        printf("Nenhum emprestimo em atraso encontrado! Parabens.\n");
    } else {
        printf("Total de emprestimos em atraso: %d\n", total_atrasos);
    }
}
    void funcao_busca_avancada() {
    char termo_busca[100];
    int resultados = 0;

    printf("\n------ Busca Avancada de Livros (Titulo, Autor, Editora) ------\n");
    printf("Digite o termo de busca (parte do nome ou autor): ");

    if (fgets(termo_busca, sizeof(termo_busca), stdin) == NULL) {
        printf("Entrada invalida.\n");
        return;
    }

    termo_busca[strcspn(termo_busca, "\n")] = 0;

    if (total_livros == 0) {
        printf("Nenhum livro cadastrado para busca.\n");
        return;
    }

    printf("\n--- RESULTADOS ENCONTRADOS ---\n");
    printf("| %-6s | %-40s | %-20s | %-10s |\n",
           "CODIGO", "TITULO", "AUTOR", "DISPON.");
    printf("|--------|-----------------------|----------------------|------------|\n");

    for (int i = 0; i < total_livros; i++) {
        Livro l = livros[i];

        if (strstr(l.titulo, termo_busca) != NULL ||
            strstr(l.autor, termo_busca) != NULL ||
            strstr(l.editora, termo_busca) != NULL)
        {

            resultados++;

            // Imprime o livro na linha da tabela
            printf("| %-6d | %-40s | %-20s | %-10d |\n",
                   l.codigo,
                   l.titulo,
                   l.autor,
                   l.num_exemplares_disponives);
        }
    }

    printf("----------------------------------------------------------------------------------\n");
    printf("Total de resultados encontrados: %d\n", resultados);
}
  void sistema_renovacao_emprestimos(){
    int cod_emprestimo;
    int indice_emprestimo;

    printf("\n------ Sistema de Renovacao de Emprestimo ------\n");

    //Entrada do Código
    printf("Digite o CODIGO do emprestimo que deseja renovar: ");
    if (scanf("%d", &cod_emprestimo) != 1) {
        printf("Entrada invalida. Tente novamente.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    // Busca do Empréstimo Ativo
    indice_emprestimo = buscar_emprestimo_por_codigo(cod_emprestimo);

    if (indice_emprestimo == -1) {
        printf(" ERRO: Emprestimo #%d nao encontrado ou ja foi devolvido.\n", cod_emprestimo);
        return;
    }

    // Pega o ponteiro direto para o empréstimo para atualização
    Emprestimo *e = &emprestimos[indice_emprestimo];

    //Obtém o tempo atual e calcula a nova data (7 dias a partir de AGORA)
    time_t tempo_atual = time(NULL);

    //7 dias * 24 hrs * 60 mts * 60 sds
    time_t novo_tempo_devolucao = tempo_atual + (7 * 24 * 60 * 60);
    struct tm *tm_nova_devolucao = localtime(&novo_tempo_devolucao);

    e->data_prevista_devolucao.dia = tm_nova_devolucao->tm_mday;
    e->data_prevista_devolucao.mes = tm_nova_devolucao->tm_mon + 1;
    e->data_prevista_devolucao.ano = tm_nova_devolucao->tm_year + 1900;

    printf("\n Renovacao do emprestimo #%d realizada com sucesso!\n", e->codigo_emprestimo);
    printf("  Nova Devolucao Prevista: %02d/%02d/%d\n",
           e->data_prevista_devolucao.dia,
           e->data_prevista_devolucao.mes,
           e->data_prevista_devolucao.ano);
}
 void relatorio_livros_mais_emprestados() {

    printf("\n---------- RELATORIO DE LIVROS MAIS EMPRESTADOS ----------\n");

    if (total_emprestimos == 0){
        printf("Nenhum emprestimo registrado para gerar o relatorio.\n");
        return;
    }

    //Zerar e Limpar o vetor de contadores para cada novo relatório
    total_contadores = 0;

    //Contagem da Frequência
    for (int i = 0; i < total_emprestimos; i++) {
        int cod_livro_atual = emprestimos[i].codigo_livro;
        int encontrado = 0;

        for (int j = 0; j < total_contadores; j++) {
            if (contadores[j].codigo_livro == cod_livro_atual){
                contadores[j].contagem++;
                encontrado = 1;
                break;
            }
        }

        // Se o livro não foi encontrado, adicione
        if (!encontrado && total_contadores < MAX_LIVROS) {
            contadores[total_contadores].codigo_livro = cod_livro_atual;
            contadores[total_contadores].contagem = 1;
            total_contadores++;
        }
    }

    //Imprimir o Relatório
    printf("| %-4s | %-6s | %-40s | %-10s |\n",
           "POS.", "CODIGO", "TITULO", "TOTAL");
    printf("|------|--------|------------------------------------------|------------|\n");

    for (int i = 0; i < total_contadores; i++) {
        // Busca os dados do livro pelo código
        int indice_livro = buscar_livro_por_codigo(contadores[i].codigo_livro);

        // Mock do buscar_livro_por_codigo
        if (contadores[i].codigo_livro == 101) indice_livro = 0;
        else if (contadores[i].codigo_livro == 102) indice_livro = 1;
        else indice_livro = -1;

        if (indice_livro != -1) {
            printf("| %-4d | %-6d | %-40s | %-10d |\n",
                   i + 1, //Posição
                   contadores[i].codigo_livro,
                   livros[indice_livro].titulo,
                   contadores[i].contagem);
        }
    }
    printf("|------|--------|------------------------------------------|------------|\n");
}

