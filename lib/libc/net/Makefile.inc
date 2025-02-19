#	from @(#)Makefile.inc	8.2 (Berkeley) 9/5/93
# $FreeBSD: src/lib/libc/net/Makefile.inc,v 1.36.2.5 2002/07/29 18:33:18 ume Exp $

# machine-independent net sources
.PATH: ${.CURDIR}/../libc/net

CMAPS+=	${.CURDIR}/net/Symbol.map

SRCS+=	base64.c ether_addr.c eui64.c \
	gai_strerror.c getaddrinfo.c \
	gethostbydns.c gethostbyht.c gethostbynis.c gethostnamadr.c \
	getifaddrs.c getnameinfo.c \
	getnetbydns.c getnetbyht.c getnetbynis.c getnetnamadr.c \
	getproto.c getprotoent.c getprotoname.c \
	getservent.c \
	if_indextoname.c if_nameindex.c if_nametoindex.c \
	ip6opt.c linkaddr.c map_v4v6.c name6.c \
	nsdispatch.c nslexer.l nsparser.y nss_compat.c ntoh.c \
	rcmd.c rcmdsh.c recv.c \
	rthdr.c sockatmark.c send.c vars.c

.if !defined(NO_NS_CACHING)
SRCS+=	nscache.c nscachedcli.c
.endif

CFLAGS+=-DINET6 -I${.OBJDIR} -I${.CURDIR}/../libc/resolv

YFLAGS+=-p_nsyy
LFLAGS+=-P_nsyy

FLAGS_GROUPS=	yy_buf
yy_buf_FLAGS=	-DYY_BUF_SIZE=1024
yy_buf_FLAGS_FILES=nslexer.c

MAN+=	byteorder.3 ethers.3 eui64.3 \
	gai_strerror.3 getaddrinfo.3 gethostbyname.3 \
	getifaddrs.3 getipnodebyname.3 \
	getnameinfo.3 getnetent.3 getprotoent.3 getservent.3 if_indextoname.3 \
	inet6_opt_init.3 inet6_option_space.3 inet6_rth_space.3 \
	inet6_rthdr_space.3 linkaddr.3 nsdispatch.3 \
	rcmd.3 rcmdsh.3 resolver.3 sockatmark.3

MLINKS+=byteorder.3 htonl.3 \
	byteorder.3 htons.3 \
	byteorder.3 ntohl.3 \
	byteorder.3 ntohs.3
MLINKS+=ethers.3 ether_aton.3 \
	ethers.3 ether_aton_r.3 \
	ethers.3 ether_hostton.3 \
	ethers.3 ether_line.3 \
	ethers.3 ether_ntoa.3 \
	ethers.3 ether_ntoa_r.3 \
	ethers.3 ether_ntohost.3
MLINKS+=eui64.3 eui64_aton.3 \
	eui64.3 eui64_hostton.3 \
	eui64.3 eui64_ntoa.3 \
	eui64.3 eui64_ntohost.3
MLINKS+=getaddrinfo.3 freeaddrinfo.3
MLINKS+=gethostbyname.3 endhostent.3 \
	gethostbyname.3 gethostbyaddr.3 \
	gethostbyname.3 gethostbyaddr_r.3 \
	gethostbyname.3 gethostbyname_r.3 \
	gethostbyname.3 gethostbyname2.3 \
	gethostbyname.3 gethostbyname2_r.3 \
	gethostbyname.3 gethostent.3 \
	gethostbyname.3 gethostent_r.3 \
	gethostbyname.3 herror.3 \
	gethostbyname.3 hstrerror.3 \
	gethostbyname.3 sethostent.3
MLINKS+=getifaddrs.3 freeifaddrs.3
MLINKS+=getipnodebyname.3 freehostent.3 \
	getipnodebyname.3 getipnodebyaddr.3
MLINKS+=getnetent.3 endnetent.3 \
	getnetent.3 getnetbyaddr.3 \
	getnetent.3 getnetbyaddr_r.3 \
	getnetent.3 getnetbyname.3 \
	getnetent.3 getnetbyname_r.3 \
	getnetent.3 getnetent_r.3 \
	getnetent.3 setnetent.3
MLINKS+=getprotoent.3 endprotoent.3 \
	getprotoent.3 getprotobyname.3 \
	getprotoent.3 getprotobyname_r.3 \
	getprotoent.3 getprotobynumber.3 \
	getprotoent.3 getprotobynumber_r.3 \
	getprotoent.3 getprotoent_r.3 \
	getprotoent.3 setprotoent.3
MLINKS+=getservent.3 endservent.3 \
	getservent.3 getservbyname_r.3 \
	getservent.3 getservbyname.3 \
	getservent.3 getservbyport.3 \
	getservent.3 getservbyport_r.3 \
	getservent.3 getservent_r.3 \
	getservent.3 setservent.3
MLINKS+=if_indextoname.3 if_freenameindex.3 \
	if_indextoname.3 if_nameindex.3 \
	if_indextoname.3 if_nametoindex.3
MLINKS+=inet6_opt_init.3 inet6_opt_append.3 \
	inet6_opt_init.3 inet6_opt_find.3 \
	inet6_opt_init.3 inet6_opt_finish.3 \
	inet6_opt_init.3 inet6_opt_get_val.3 \
	inet6_opt_init.3 inet6_opt_next.3 \
	inet6_opt_init.3 inet6_opt_set_val.3
MLINKS+=inet6_option_space.3 inet6_option_alloc.3 \
	inet6_option_space.3 inet6_option_append.3 \
	inet6_option_space.3 inet6_option_find.3 \
	inet6_option_space.3 inet6_option_init.3 \
	inet6_option_space.3 inet6_option_next.3
MLINKS+=inet6_rth_space.3 inet6_rth_add.3 \
	inet6_rth_space.3 inet6_rth_getaddr.3 \
	inet6_rth_space.3 inet6_rth_init.3 \
	inet6_rth_space.3 inet6_rth_reverse.3 \
	inet6_rth_space.3 inet6_rth_segments.3
MLINKS+=inet6_rthdr_space.3 inet6_rthdr_add.3 \
	inet6_rthdr_space.3 inet6_rthdr_getaddr.3 \
	inet6_rthdr_space.3 inet6_rthdr_getflags.3 \
	inet6_rthdr_space.3 inet6_rthdr_init.3 \
	inet6_rthdr_space.3 inet6_rthdr_lasthop.3 \
	inet6_rthdr_space.3 inet6_rthdr_reverse.3 \
	inet6_rthdr_space.3 inet6_rthdr_segments.3
MLINKS+=linkaddr.3 link_addr.3 \
	linkaddr.3 link_ntoa.3 
MLINKS+=rcmd.3 iruserok.3 \
	rcmd.3 iruserok_sa.3 \
	rcmd.3 rcmd_af.3 \
	rcmd.3 rresvport.3 \
	rcmd.3 rresvport_af.3 \
	rcmd.3 ruserok.3
MLINKS+=resolver.3 dn_comp.3 \
	resolver.3 dn_expand.3 \
	resolver.3 dn_skipname.3 \
	resolver.3 ns_get16.3 \
	resolver.3 ns_get32.3 \
	resolver.3 ns_put16.3 \
	resolver.3 ns_put32.3 \
	resolver.3 res_init.3 \
	resolver.3 res_mkquery.3 \
	resolver.3 res_query.3 \
	resolver.3 res_search.3 \
	resolver.3 res_send.3

.if defined(WANT_HESIOD)
SRCS+=	hesiod.c
MAN+=	hesiod.3
MLINKS+=hesiod.3 hesiod_end.3 \
	hesiod.3 hesiod_free_list.3 \
	hesiod.3 hesiod_init.3 \
	hesiod.3 hesiod_resolve.3 \
	hesiod.3 hesiod_to_bind.3
.endif
