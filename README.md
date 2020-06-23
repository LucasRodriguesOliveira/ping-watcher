# Ping Watcher

Boas vindas ao Ping Watcher

Esta ferramenta visa auxiliar computadores que tem uma placa de rede obsoleta/danificada ou possíveis conflitos na rede onde o computador desconecta da rede conectada com frequência.

Para utilizar, basta adicionar o arquivo .exe em qualquer lugar da sua preferência e executá-lo via linha de comando, por exemplo:

`C:>ping_watcher <maxtime>`

onde *maxtime* é o tempo limite no qual será efetuado a observação, caso o programa detecte duas ocorrências que ultrapassam esse limite, automaticamente reconecta o computador novamente

o programa utiliza de comandos simples como *ping 8.8.8.8*, *ipconfig /release* e *ipconfig /renew*, porém para evitar de manualmente ter de realizar essas ações, pode deixar o programa executando que será feito automaticamente

Prós: evita o serviço manual de reconectar novamente na rede Wi-Fi
Contra:
 - é uma versão alpha, e acaba por gerar um arquivo utilizado para verificar as ocorrências
 - Na primeira execução, pode indicar falha, mas em futuras versões isso pode ser corrigido
 - Para executar por clique, é necessário criar um atalho e passar o parâmetro <maxtime> ao final do caminho do .exe, dessa forma:

`"C:/ping_watcher.exe" <maxtime>`

Agradeço a visita. Se tiver sugestões de melhorias, pode abrir uma issue que irei verificar :)
