require("exemplo");

print("Teste das funcoes");
print(exemplo.funcao_um());
print(exemplo.funcao_dois());
exemplo.funcao_tres();

print("Teste da struct");
p= exemplo.Ponto();
p.x=3;
p.y=5;
print(p.x,p.y);

print("Teste dos defines");
print(exemplo.DEFINE_UM);
print(exemplo.DEFINE_DOIS);

print("Teste dos enums");
print(exemplo.ENUM_TESTE1, exemplo.ENUM_TESTE2, exemplo.ENUM_TESTE3);

print("Testando ifdef");
print(exemplo.OS);

print("Testando estrutura opaca");
v = exemplo.aloca_vetor(5, 20, 7);
exemplo.imprimir_vetor(v);
