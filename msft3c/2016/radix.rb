digitos = "0123456789abcdefghijklmnopqrstuvwxyz".chars
entradas=gets
entradas = entradas.split ","
palavra = entradas[0].chars
base_velha = entradas[1].to_i
base_nova = entradas[2].to_i
valor = 0
pot=1
for c in palavra.reverse
	valor+=(digitos.find_index c)*pot
	pot*=base_velha
end
resposta=""
while valor>0
	resposta+=digitos[valor%base_nova]
	valor-=(valor%base_nova)
	valor = valor/base_nova
end
puts resposta

