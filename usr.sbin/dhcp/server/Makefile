# $NetBSD: Makefile,v 1.18 2011/09/13 14:00:08 plunky Exp $

.include <bsd.own.mk>

SRCS   = dhcpd.c dhcp.c bootp.c confpars.c db.c class.c failover.c \
         omapi.c mdb.c stables.c salloc.c ddns.c
PROG   = dhcpd
MAN    = dhcpd.8 dhcpd.conf.5 dhcpd.leases.5

DHCPSRCDIR=	server

.if ${MKSHARE} != "no"
FILESDIR= /usr/share/examples/dhcp

FILES=	dhcpd.conf
.endif

.include <bsd.prog.mk>
