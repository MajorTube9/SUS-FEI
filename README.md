# SUS-do-tio-LULU 📋

Um sistema completo de gerenciamento de atendimento médico implementado em C, utilizando diversas estruturas de dados para organizar eficientemente o fluxo de pacientes.

## 🏗️ Estruturas de Dados Implementadas

| Estrutura                  | Finalidade                                  |
|----------------------------|--------------------------------------------|
| Lista Encadeada            | Cadastro geral de pacientes                |
| Fila                       | Gerenciamento de atendimento regular       |
| Heap (Fila Prioritária)    | Atendimento prioritário por idade          |
| Árvore Binária de Busca    | Pesquisas e relatórios                     |
| Pilha                      | Controle de operações (funcionalidade de desfazer) |

## 🚀 Funcionalidades Principais

### 👥 Cadastro de Pacientes
- ✅ Cadastrar novo paciente
- 🔍 Consultar paciente cadastrado
- 📜 Mostrar lista completa
- ✏️ Atualizar dados de paciente
- ❌ Remover paciente

### 🏥 Atendimento
- ➕ Enfileirar paciente para atendimento regular
- ➖ Desenfileirar paciente
- 👀 Mostrar fila de atendimento

### ⚠️ Atendimento Prioritário
- 🔼 Enfileirar paciente (prioridade por idade)
- 🔽 Desenfileirar paciente prioritário
- 📊 Mostrar fila prioritária (capacidade máxima: 20 pacientes/dia)

### 🔎 Pesquisa e Relatórios
Mostrar registros ordenados por:
- 📅 Ano de registro
- 🗓️ Mês de registro
- 📆 Dia de registro
- 👴👶 Idade do paciente

### ⏪ Controle de Operações
- 📜 Visualizar histórico de operações
- ↩️ Desfazer última operação na fila de atendimento

### 💾 Persistência de Dados
- 📥 Carregar dados de arquivo
- 📤 Salvar dados em arquivo
- 🔄 Manutenção da ordem de inserção

## 🛠️ Tecnologias Utilizadas
- Linguagem C
- Estruturas de dados dinâmicas
- Manipulação de arquivos

## 📂 Arquivos Inclusos
- Código fonte completo e comentado
- Arquivo de dados com 10 registros de pacientes para testes

## 👥 Desenvolvimento
Projeto desenvolvido individualmente ou em dupla (conforme especificação)

## 🎯 Objetivos Alcançados
- Implementação robusta de múltiplas estruturas de dados
- Sistema completo de gerenciamento de pacientes
- Persistência de dados
- Controle de operações com funcionalidade de desfazer
- Múltiplas formas de visualização e ordenação de dados

## 📝 Como Utilizar
1. Compile o código fonte
2. Execute o programa
3. Utilize o menu interativo para acessar todas as funcionalidades
4. Os dados são automaticamente salvos ao finalizar o programa

## 📊 Exemplo de Dados de Teste
O sistema inclui um arquivo com registros de exemplo contendo:
- Nomes de pacientes
- Idades variadas
- Datas de registro diversificadas

## 📚 Documentação
O código está completamente comentado para facilitar a compreensão e manutenção.
