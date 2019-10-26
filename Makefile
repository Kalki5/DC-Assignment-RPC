all: build bin/server bin/client

bin/server: src/server.c
	gcc -lrpcsvc -lnsl -o bin/server src/server.c src/common/calculator_svc.c src/common/calculator_xdr.c

bin/client: src/client.c
	gcc -lnsl -o bin/client src/client.c src/common/calculator_clnt.c src/common/calculator_xdr.c

build:
	mkdir -p bin

rpcgen:
	cd src/common/ && rpcgen -C calculator.x

rpcclean:
	rm -rf src/common/calculator.h src/common/calculator_*.c 

clean:
	rm -rf bin
