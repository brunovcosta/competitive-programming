for file in *.cpp; do
	number=$(echo $file | cut -c5-8)
	url=$(echo http://www.urionlinejudge.com.br/repository/UOJ_${number}.html)
	html=$(curl $url -s)
	nome=$(echo $html | sed -n -e 's!.*<title>\(.*\)</title>.*!\1!p' | cut -c12-)
	formatado=$(echo $nome | sed -e "s/\ /_/g")
	mv  "$file" "${formatado}.cpp"
	echo "${formatado}.cpp"
done
