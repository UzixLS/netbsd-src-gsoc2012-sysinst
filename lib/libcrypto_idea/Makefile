#	$NetBSD: Makefile,v 1.7 2010/07/06 05:59:52 mrg Exp $

# RCSid:
#	Id: Makefile,v 1.33 1998/11/11 11:53:53 sjg Exp
#
#	@(#) Copyright (c) 1994 Simon J. Gerraty
#
#	This file is provided in the hope that it will
#	be of use.  There is absolutely NO WARRANTY.
#	Permission to copy, redistribute or otherwise
#	use this file is hereby granted provided that 
#	the above copyright notice and this notice are
#	left intact. 
#      
#	Please send copies of changes and bug-fixes to:
#	sjg@quick.com.au
#

NOPIC=		# defined
#NOPROFILE=	# defined
#NOLINT=	# defined

.include <bsd.own.mk>

# XXX There's a bit of work to do before we can enable warnings.
WARNS=		0

LIB=		crypto_idea
CPPFLAGS+=	-Dlib${LIB} -I. -I${OPENSSLSRC}/crypto -I${OPENSSLSRC}

CRYPTODIST=	${NETBSDSRCDIR}/crypto/dist

.include "${NETBSDSRCDIR}/crypto/Makefile.openssl"

.PATH: ${OPENSSLSRC} ${OPENSSLSRC}/crypto/idea ${OPENSSLSRC}/crypto/evp

CPPFLAGS+=	-I${OPENSSLSRC}/crypto/idea
SRCS+=		i_cbc.c i_skey.c e_idea.c c_allc.c

AFLAGS+=	-DELF

.include <bsd.lib.mk>
