#include "run-command.h"
		drv->name = xmemdupz(name, namelen);
		pp->name = xmemdupz(name, namelen);
	struct strbuf res;
	strbuf_init(&res, 0);
		strbuf_addch(&res, '"');
		quote_c_style(one, &res, NULL, 1);
		quote_c_style(two, &res, NULL, 1);
		strbuf_addch(&res, '"');
	} else {
		strbuf_addstr(&res, one);
		strbuf_addstr(&res, two);
	return strbuf_detach(&res, NULL);
	struct strbuf name;
	int a_midlen, b_midlen;
	strbuf_init(&name, 0);
		quote_c_style(a, &name, NULL, 0);
		strbuf_addstr(&name, " => ");
		quote_c_style(b, &name, NULL, 0);
		return strbuf_detach(&name, NULL);
	a_midlen = len_a - pfx_length - sfx_length;
	b_midlen = len_b - pfx_length - sfx_length;
	if (a_midlen < 0)
		a_midlen = 0;
	if (b_midlen < 0)
		b_midlen = 0;

	strbuf_grow(&name, pfx_length + a_midlen + b_midlen + sfx_length + 7);
		strbuf_add(&name, a, pfx_length);
		strbuf_addch(&name, '{');
	strbuf_add(&name, a + pfx_length, a_midlen);
	strbuf_addstr(&name, " => ");
	strbuf_add(&name, b + pfx_length, b_midlen);
	if (pfx_length + sfx_length) {
		strbuf_addch(&name, '}');
		strbuf_add(&name, a + len_a - sfx_length, sfx_length);
	return strbuf_detach(&name, NULL);
	reset = diff_get_color_opt(options, DIFF_RESET);
	set   = diff_get_color_opt(options, DIFF_PLAIN);
	add_c = diff_get_color_opt(options, DIFF_FILE_NEW);
	del_c = diff_get_color_opt(options, DIFF_FILE_OLD);
			struct strbuf buf;
			strbuf_init(&buf, 0);
			if (quote_c_style(file->name, &buf, NULL, 0)) {
				file->name = strbuf_detach(&buf, NULL);
			} else {
				strbuf_release(&buf);
		if (!file->is_renamed) {
			write_name_quoted(file->name, stdout, options->line_termination);
		} else {
			putchar(options->line_termination);
		}
	const char *set = diff_get_color_opt(o, DIFF_METAINFO);
	const char *reset = diff_get_color_opt(o, DIFF_RESET);
					DIFF_OPT_TST(o, COLOR_DIFF));
	if (!DIFF_OPT_TST(o, TEXT) &&
		if (DIFF_OPT_TST(o, BINARY))
		ecbdata.color_diff = DIFF_OPT_TST(o, COLOR_DIFF);
		if (DIFF_OPT_TST(o, COLOR_DIFF_WORDS))
		if (DIFF_OPT_TST(o, COLOR_DIFF_WORDS))
	data.color_diff = DIFF_OPT_TST(o, COLOR_DIFF);
	spec->count = 1;
void free_filespec(struct diff_filespec *spec)
{
	if (!--spec->count) {
		diff_free_filespec_data(spec);
		free(spec);
	}
}

	struct strbuf buf;
	size_t size = 0;

	strbuf_init(&buf, 0);
	if (strbuf_read(&buf, 0, 0) < 0)
		return error("error while reading from stdin %s",

	s->data = strbuf_detach(&buf, &size);
		struct strbuf buf;
		strbuf_init(&buf, 0);
		if (convert_to_git(s->path, s->data, s->size, &buf)) {
			size_t size = 0;
			s->data = strbuf_detach(&buf, &size);
	fflush(NULL);
	retval = run_command_v_opt(spawn_arg, 0);
	if (!DIFF_OPT_TST(o, ALLOW_EXTERNAL))
	struct strbuf msg;
	char *xfrm_msg;
	struct diff_filespec *one = p->one;
	struct diff_filespec *two = p->two;

	name  = p->one->path;
	strbuf_init(&msg, PATH_MAX * 2 + 300);
		strbuf_addf(&msg, "similarity index %d%%", similarity_index(p));
		strbuf_addstr(&msg, "\ncopy from ");
		quote_c_style(name, &msg, NULL, 0);
		strbuf_addstr(&msg, "\ncopy to ");
		quote_c_style(other, &msg, NULL, 0);
		strbuf_addch(&msg, '\n');
		strbuf_addf(&msg, "similarity index %d%%", similarity_index(p));
		strbuf_addstr(&msg, "\nrename from ");
		quote_c_style(name, &msg, NULL, 0);
		strbuf_addstr(&msg, "\nrename to ");
		quote_c_style(other, &msg, NULL, 0);
		strbuf_addch(&msg, '\n');
			strbuf_addf(&msg, "dissimilarity index %d%%\n",
		int abbrev = DIFF_OPT_TST(o, FULL_INDEX) ? 40 : DEFAULT_ABBREV;
		if (DIFF_OPT_TST(o, BINARY)) {
		strbuf_addf(&msg, "index %.*s..%.*s",
			strbuf_addf(&msg, " %06o", one->mode);
		strbuf_addch(&msg, '\n');
	if (msg.len)
		strbuf_setlen(&msg, msg.len - 1);
	xfrm_msg = msg.len ? msg.buf : NULL;
	strbuf_release(&msg);
	if (diff_use_color_default)
		DIFF_OPT_SET(options, COLOR_DIFF);
	else
		DIFF_OPT_CLR(options, COLOR_DIFF);
	if (DIFF_OPT_TST(options, FIND_COPIES_HARDER))
		DIFF_OPT_SET(options, RECURSIVE);
		DIFF_OPT_SET(options, RECURSIVE);
	if (DIFF_OPT_TST(options, QUIET)) {
		DIFF_OPT_SET(options, EXIT_WITH_STATUS);
		DIFF_OPT_CLR(options, QUIET);

	/* Output format options */
	else if (!strcmp(arg, "--patch-with-raw"))
	else if (!strcmp(arg, "--numstat"))
	else if (!strcmp(arg, "--shortstat"))
	else if (!strcmp(arg, "--check"))
		options->output_format |= DIFF_FORMAT_CHECKDIFF;
	else if (!strcmp(arg, "--summary"))
		options->output_format |= DIFF_FORMAT_SUMMARY;
	else if (!strcmp(arg, "--patch-with-stat"))
		options->output_format |= DIFF_FORMAT_PATCH | DIFF_FORMAT_DIFFSTAT;
	else if (!strcmp(arg, "--name-only"))
		options->output_format |= DIFF_FORMAT_NAME;
	else if (!strcmp(arg, "--name-status"))
		options->output_format |= DIFF_FORMAT_NAME_STATUS;
	else if (!strcmp(arg, "-s"))
		options->output_format |= DIFF_FORMAT_NO_OUTPUT;

	/* renames options */
		if ((options->break_opt = diff_scoreopt_parse(arg)) == -1)
		if ((options->rename_score = diff_scoreopt_parse(arg)) == -1)
			DIFF_OPT_SET(options, FIND_COPIES_HARDER);
		if ((options->rename_score = diff_scoreopt_parse(arg)) == -1)
	else if (!strcmp(arg, "--no-renames"))
		options->detect_rename = 0;

	/* xdiff options */

	/* flags options */
	else if (!strcmp(arg, "--binary")) {
		options->output_format |= DIFF_FORMAT_PATCH;
		DIFF_OPT_SET(options, BINARY);
	}
	else if (!strcmp(arg, "--full-index"))
		DIFF_OPT_SET(options, FULL_INDEX);
	else if (!strcmp(arg, "-a") || !strcmp(arg, "--text"))
		DIFF_OPT_SET(options, TEXT);
	else if (!strcmp(arg, "-R"))
		DIFF_OPT_SET(options, REVERSE_DIFF);
	else if (!strcmp(arg, "--find-copies-harder"))
		DIFF_OPT_SET(options, FIND_COPIES_HARDER);
	else if (!strcmp(arg, "--follow"))
		DIFF_OPT_SET(options, FOLLOW_RENAMES);
	else if (!strcmp(arg, "--color"))
		DIFF_OPT_SET(options, COLOR_DIFF);
	else if (!strcmp(arg, "--no-color"))
		DIFF_OPT_CLR(options, COLOR_DIFF);
		options->flags |= DIFF_OPT_COLOR_DIFF | DIFF_OPT_COLOR_DIFF_WORDS;
		DIFF_OPT_SET(options, EXIT_WITH_STATUS);
		DIFF_OPT_SET(options, QUIET);
		DIFF_OPT_SET(options, ALLOW_EXTERNAL);
		DIFF_OPT_CLR(options, ALLOW_EXTERNAL);

	/* misc options */
	else if (!strcmp(arg, "-z"))
		options->line_termination = 0;
	else if (!prefixcmp(arg, "-l"))
		options->rename_limit = strtoul(arg+2, NULL, 10);
	else if (!prefixcmp(arg, "-S"))
		options->pickaxe = arg + 2;
	else if (!strcmp(arg, "--pickaxe-all"))
		options->pickaxe_opts = DIFF_PICKAXE_ALL;
	else if (!strcmp(arg, "--pickaxe-regex"))
		options->pickaxe_opts = DIFF_PICKAXE_REGEX;
	else if (!prefixcmp(arg, "-O"))
		options->orderfile = arg + 2;
	else if (!prefixcmp(arg, "--diff-filter="))
		options->filter = arg + 14;
	else if (!strcmp(arg, "--abbrev"))
		options->abbrev = DEFAULT_ABBREV;
	else if (!prefixcmp(arg, "--abbrev=")) {
		options->abbrev = strtoul(arg + 9, NULL, 10);
		if (options->abbrev < MINIMUM_ABBREV)
			options->abbrev = MINIMUM_ABBREV;
		else if (40 < options->abbrev)
			options->abbrev = 40;
	}
	free_filespec(p->one);
	free_filespec(p->two);
static void diff_flush_raw(struct diff_filepair *p, struct diff_options *opt)
	int line_termination = opt->line_termination;
	int inter_name_termination = line_termination ? '\t' : '\0';
	if (!(opt->output_format & DIFF_FORMAT_NAME_STATUS)) {
		printf(":%06o %06o %s ", p->one->mode, p->two->mode,
		       diff_unique_abbrev(p->one->sha1, opt->abbrev));
		printf("%s ", diff_unique_abbrev(p->two->sha1, opt->abbrev));
	if (p->score) {
		printf("%c%03d%c", p->status, similarity_index(p),
			   inter_name_termination);
	} else {
		printf("%c%c", p->status, inter_name_termination);
	if (p->status == DIFF_STATUS_COPIED || p->status == DIFF_STATUS_RENAMED) {
		write_name_quoted(p->one->path, stdout, inter_name_termination);
		write_name_quoted(p->two->path, stdout, line_termination);
	} else {
		const char *path = p->one->mode ? p->one->path : p->two->path;
		write_name_quoted(path, stdout, line_termination);
	}
	struct diff_filespec *one = p->one, *two = p->two;
	fprintf(stderr, "score %d, status %c rename_used %d broken %d\n",
		p->one->rename_used, p->broken_pair);
	int i;
	struct diff_filepair *p;
			/*
			 * A rename might have re-connected a broken
			 * pair up, causing the pathnames to be the
			 * same again. If so, that's not a rename at
			 * all, just a modification..
			 *
			 * Otherwise, see if this source was used for
			 * multiple renames, in which case we decrement
			 * the count, and call it a copy.
			if (!strcmp(p->one->path, p->two->path))
				p->status = DIFF_STATUS_MODIFIED;
			else if (--p->one->rename_used > 0)
			else
		write_name_quoted(p->two->path, stdout, opt->line_termination);
		printf(" %s mode %06o ", newdelete, fs->mode);
		printf(" %s ", newdelete);
	write_name_quoted(fs->path, stdout, '\n');
		printf(" mode change %06o => %06o%c", p->one->mode, p->two->mode,
			show_name ? ' ' : '\n');
			write_name_quoted(p->two->path, stdout, '\n');
			puts(" rewrite ");
			write_name_quoted(p->two->path, stdout, ' ');
			printf("(%d%%)\n", similarity_index(p));
		}
		show_mode_change(p, !p->score);
	char *dst = line;
	unsigned char c;
	for (i = 0; i < len; i++)
		if (!isspace((c = line[i])))
			*dst++ = c;
	return dst - line;
			if (!DIFF_OPT_TST(diffopt, NO_INDEX))
	if (DIFF_OPT_TST(options, QUIET))
	if (options->skip_stat_unmatch && !DIFF_OPT_TST(options, FIND_COPIES_HARDER))
	if (diff_queued_diff.nr)
		DIFF_OPT_SET(options, HAS_CHANGES);
	else
		DIFF_OPT_CLR(options, HAS_CHANGES);
	if (DIFF_OPT_TST(options, REVERSE_DIFF))
	DIFF_OPT_SET(options, HAS_CHANGES);
	if (DIFF_OPT_TST(options, REVERSE_DIFF)) {
	DIFF_OPT_SET(options, HAS_CHANGES);