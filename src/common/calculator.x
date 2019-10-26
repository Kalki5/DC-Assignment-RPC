struct request {
    int x;
    int y;
    int ans;
    int choice;
};

struct response {
    int value;
    int code;
};

program calc_prg {
    version calc_version {
        response calc(request) = 1;
    } = 1;
} = 0x32345676;