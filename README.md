# echo-rpc

## Build

```
$> mkdir -p BUILD
$> cd BUILD/
$> cmake ../
$> cd ..
$> cmake .
$> cmake --build .
```
## Test
```
$> curl --header "Content-Type: application/json" --request POST --data '{"jsonrpc":"2.0", "method":"ping", "params":{}, "id":1}' http://127.0.0.1:10082/rpc | python -m json.tool
```
