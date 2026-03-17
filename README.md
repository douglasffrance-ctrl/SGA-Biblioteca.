\# SGA - Sistema de Gerenciamento de Biblioteca .



!\[C](https://img.shields.io/badge/C-00599C?style=for-the-badge\&logo=c\&logoColor=white)

!\[Code::Blocks](https://img.shields.io/badge/Code::Blocks-4A90E2?style=for-the-badge\&logo=codeblocks\&logoColor=white)

!\[Status](https://img.shields.io/badge/Status-Em\_Desenvolvimento-success?style=for-the-badge)



\## Sobre o Projeto

O \*\*SGA (Sistema de Gerenciamento de Biblioteca)\*\* é uma aplicação via Interface de Linha de Comando (CLI) desenvolvida inteiramente em linguagem C. Este projeto foi construído com o objetivo de aplicar conceitos fundamentais de programação estruturada, gerenciamento de estado e persistência de dados.



O sistema simula a operação real de uma biblioteca, permitindo o controle de acervo, registro de usuários e a lógica de negócios de empréstimos, devoluções e cálculo de atrasos.



\## Funcionalidades



O sistema está dividido em módulos funcionais acessíveis por um menu interativo:



\* \*\*Gestão de Acervo (Livros):\*\* Cadastro detalhado, controle de exemplares disponíveis e inativação de registros.

\* \*\*Gestão de Usuários:\*\* Registro de alunos/usuários, incluindo geração automática de matrícula e controle de status.

\* \*\*Operações de Empréstimo:\*\* Validação de disponibilidade do acervo, cálculo automático de data de devolução (7 dias) e registro de devoluções.

\* \*\*Relatórios Avançados:\*\* \* Levantamento de usuários com devoluções em atraso.

&nbsp; \* Mecanismo de busca avançada por strings (título, autor ou editora).

\* \*\*Persistência de Dados (Arquivos Binários):\*\* \* Salvamento e carregamento automático do estado do sistema utilizando arquivos `.dat`.

&nbsp; \* Sistema de rotina de backup de segurança (`\_backup.dat`).



\## Destaques Técnicos



Este projeto demonstra domínio sobre os seguintes conceitos de base:

\* \*\*Estruturas de Dados:\*\* Uso extensivo de `structs` e arrays multidimensionais para gerenciamento de entidades complexas.

\* \*\*Manipulação de Arquivos (File I/O):\*\* Leitura e escrita em formato binário (`fread`, `fwrite`) garantindo a integridade e persistência das informações entre execuções.

\* \*\*Manipulação de Tempo:\*\* Integração com a biblioteca `<time.h>` para gerar datas automáticas de empréstimo e devolução baseadas no relógio do sistema operacional.

\* \*\*Validação de Entrada:\*\* Tratamento de buffer de teclado para evitar loops infinitos ou falhas de segmentação durante a interação do usuário.



\## Como Executar:



O projeto foi desenvolvido prioritariamente para ambiente Windows utilizando a IDE Code::Blocks.



\### Executando pelo Code::Blocks

1\. Abra o projeto no Code::Blocks.



2\. Compile o projeto utilizando a opção \*\*Build and Run (F9)\*\*.



3\. O sistema será executado no terminal da IDE.



\### Executando pelo terminal (GCC)



```bash

git clone https://github.com/seu-usuario/sga-biblioteca-c.git

cd sga-biblioteca-c

gcc main.c -o sga.exe

sga.exe

```

