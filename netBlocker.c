
#include <stdio.h>
#include <stdlib.h>

void block_ip(const char *ip_address) {
    char command[256];

    // Construct the command to block the IP address using iptables
    snprintf(command, sizeof(command), "iptables -A INPUT -s %s -j DROP", ip_address);

    // Execute the command
    int result = system(command);

    // Check if the command executed successfully
    if (result == 0) {
        printf("Successfully blocked IP address: %s\n", ip_address);
    } else {
        printf("Failed to block IP address: %s\n", ip_address);
    }
}

int main() {
    const char *ip_to_block = "127.0.0.1"; // Replace with the API's IP address you want to block

    block_ip(ip_to_block);

    return 0;
}