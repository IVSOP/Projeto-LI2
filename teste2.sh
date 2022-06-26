for file in testes/*.in; do teste=${file%%.in}; valgrind --tool=memcheck --leak-check=full --show-reachable=yes --num-callers=20 --track-fds=yes --track-origins=yes --error-exitcode=1 ./a.out < $file; echo $teste; echo $?; ./a.out < $file | diff - $teste.out; done