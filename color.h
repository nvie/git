#ifndef COLOR_H
#define COLOR_H

/* "\033[1;38;5;2xx;48;5;2xxm\0" is 23 bytes */
#define COLOR_MAXLEN 24

/*
 * This variable stores the value of color.ui
 */
extern int git_use_color_default;

extern int branch_use_color;
extern int diff_use_color_default;
extern int wt_status_use_color;

/*
 * Use this instead of git_default_config if you need the value of color.ui.
 */
int git_color_default_config(const char *var, const char *value, void *cb);

void git_finish_color_config(void);
int git_config_colorbool(const char *var, const char *value, int stdout_is_tty);
void color_parse(const char *value, const char *var, char *dst);
void color_parse_mem(const char *value, int len, const char *var, char *dst);
int color_fprintf(FILE *fp, const char *color, const char *fmt, ...);
int color_fprintf_ln(FILE *fp, const char *color, const char *fmt, ...);
int color_fwrite_lines(FILE *fp, const char *color, size_t count, const char *buf);

#endif /* COLOR_H */
