#include <echo_rpc.hpp>

int main(void)
{
    pca::echo_rpc rpc("127.0.0.1", 10082);
    rpc.set_allow_cors(true);

    fprintf(stdout, "started echo-rpc daemon\n");

    rpc.run();
}
