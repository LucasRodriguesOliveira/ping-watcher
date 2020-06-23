#Ping Watcher

Boas vindas ao Ping Watcher

Esta ferramenta visa auxiliar computadores que tem uma placa de rede obsoleta/danificada ou poss�veis conflitos na rede onde o computador desconecta da rede conectada com frequ�ncia.

Para utilizar, basta adicionar o arquivo .exe em qualquer lugar da sua prefer�ncia e execut�-lo via linha de comando, por exemplo:

`C:>ping_watcher <maxtime>`

onde *maxtime* � o tempo limite no qual ser� efetuado a observa��o, caso o programa detecte duas ocorr�ncias que ultrapassam esse limite, automaticamente reconecta o computador novamente

o programa utiliza de comandos simples como *ping 8.8.8.8*, *ipconfig /release* e *ipconfig /renew*, por�m para evitar de manualmente ter de realizar essas a��es, pode deixar o programa executando que ser� feito automaticamente

Pr�s: evita o servi�o manual de reconectar novamente na rede Wi-Fi
Contra:
 - � uma vers�o alpha, e acaba por gerar um arquivo utilizado para verificar as ocorr�ncias
 - Na primeira execu��o, pode indicar falha, mas em futuras vers�es isso pode ser corrigido
 - Para executar por clique, � necess�rio criar um atalho e passar o par�metro <maxtime> ao final do caminho do .exe, dessa forma:

`"C:/ping_watcher.exe" <maxtime>`

Agrade�o a visita. Se tiver sugest�es de melhorias, pode abrir uma issue que irei verificar :)