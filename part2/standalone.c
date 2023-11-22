#include "standalone.h"

int main(int argc, char *argv[]) {
	// Handle input
	if (argc != 2) {
		printf("Usage: ./compdetect_client file_name\n");
		exit(-1);
	}
	printf("About to read from %s...\n", argv[1]);
	struct config_details config;	// Initialize config struct
	char file_contents[MAX_CONFIG_SIZE];		// Initialize buffer for config.json file contents

	// Parse config.json file (argv[1]), and populate config struct
	// Fill file_contents with config.json contents
	read_config_from_file(argv[1], &config, file_contents);	
	printf("successfully read and parsed %s\n", argv[1]);
	printf("About to create and send head SYN packet...\n");
	for (int i = 0; i < 100; i++) {
		tcp_syn(config.dest_port_tcp_head, config.server_ip);
	}
	printf("Successfully sent head SYN packet\n");
	
	return 0;	// Success
	
}