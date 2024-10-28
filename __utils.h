#ifndef __UTILS_H
#define __UTILS_H

size_t g_idx = 0;

#define TEST(...) { \
		char exp_buf[BUF_SIZE]; \
		char res_buf[BUF_SIZE]; \
		int exp; \
		int res; \
		int so_backup; \
		FILE *tmp; \
		tmp = tmpfile(); \
		if (!tmp) \
			return 1; \
		fflush(stdout); \
		so_backup = dup(fileno(stdout)); \
		dup2(fileno(tmp), fileno(stdout)); \
		res = ft_printf(__VA_ARGS__); \
		fflush(stdout); \
		dup2(so_backup, fileno(stdout)); \
		close(so_backup); \
		fseek(tmp, 0, SEEK_SET); \
		fgets(res_buf, BUF_SIZE, tmp); \
		fclose(tmp); \
		tmp = tmpfile(); \
		if (!tmp) \
			return 1; \
		fflush(stdout); \
		so_backup = dup(fileno(stdout)); \
		dup2(fileno(tmp), fileno(stdout)); \
		exp = printf(__VA_ARGS__); \
		fflush(stdout); \
		dup2(so_backup, fileno(stdout)); \
		close(so_backup); \
		fseek(tmp, 0, SEEK_SET); \
		fgets(exp_buf, BUF_SIZE, tmp); \
		fclose(tmp); \
		int isok = res == exp; \
		int isok_buf = strcmp(res_buf, exp_buf) == 0; \
		if (isok && isok_buf) { \
			printf("\x1b[32m.\x1b[39m"); \
		} else { \
			printf("\n"); \
			fflush(stdout); \
			fprintf(stderr, "\x1b[31m[fail]\x1b[39m: No.%zu\n", g_idx); \
			if (!isok) { \
				fprintf(stderr, "return diff: %d != %d\n", res, exp); \
			} \
			if (!isok_buf) { \
				res_buf[BUF_SIZE - 1] = '\0'; \
				exp_buf[BUF_SIZE - 1] = '\0'; \
				fprintf(stderr, "output diff: %s != %s\n", res_buf, exp_buf); \
			} \
		} \
		g_idx++; \
	}


#endif