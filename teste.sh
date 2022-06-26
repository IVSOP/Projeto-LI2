for file in testes/*.in; do teste=${file%%.in}; echo $teste; ./a.out < $file | diff - $teste.out; done
