# $NetBSD: Makefile,v 1.1 2011/04/13 19:16:52 elric Exp $

USE_FORT?= yes	# network protocol library

NOLINT=		# defined

.include <bsd.own.mk>
.include <${.CURDIR}/../../Makefile.inc>

.PATH:		${HEIMDIST}/lib/kadm5

LIB=		kadm5srv

LIBDPLIBS+=	krb5	${.CURDIR}/../libkrb5 \
		hdb	${.CURDIR}/../libhdb \
		roken	${.CURDIR}/../libroken

HEIMSRCS= kadm5_err.et

SRCS =				\
	acl.c			\
	bump_pw_expire.c	\
	chpass_s.c		\
	common_glue.c		\
	context_s.c		\
	create_s.c		\
	delete_s.c		\
	destroy_s.c		\
	ent_setup.c		\
	error.c			\
	flush_s.c		\
	free.c			\
	get_princs_s.c		\
	get_s.c			\
	init_s.c		\
	keys.c			\
	log.c			\
	marshall.c		\
	modify_s.c		\
	password_quality.c	\
	privs_s.c		\
	randkey_s.c		\
	rename_s.c		\
	server_glue.c		\
	set_keys.c		\
	set_modifier.c

MAN= kadm5_pwcheck.3

.include <${HEIMBASE}/Makefile.rules.inc>
.include <bsd.lib.mk>
