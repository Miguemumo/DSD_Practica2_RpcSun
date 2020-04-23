all : cliente server

cliente:
	cc calculator_client.c calculator_clnt.c calculator_xdr.c -o cliente -lnsl

server:
	cc calculator_server.c calculator_svc.c calculator_xdr.c -o servidor -lnsl -lm

