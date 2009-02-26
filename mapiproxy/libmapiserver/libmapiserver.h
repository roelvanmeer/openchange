/*
   libmapiserver - MAPI library for Server side

   OpenChange Project

   Copyright (C) Julien Kerihuel 2009

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef	__LIBMAPISERVER_H__
#define	__LIBMAPISERVER_H__

#ifndef	_GNU_SOURCE
#define	_GNU_SOURCE 1
#endif

#include <sys/types.h>

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#include <dcerpc.h>
#include <param.h>

#include <gen_ndr/exchange.h>

#ifndef	__BEGIN_DECLS
#ifdef	__cplusplus
#define	__BEGIN_DECLS		extern "C" {
#define	__END_DECLS		}
#else
#define	__BEGIN_DECLS
#define	__END_DECLS
#endif
#endif

#define	SIZE_DFLT_MAPI_RESPONSE	6

/* Rops default and static size */

/**
   \details OpenFolderRop has fixed response size for
   -# HasRules: uint8_t
   -# IsGhosted: uint8_t   
 */
#define	SIZE_DFLT_ROPOPENFOLDER			2

/**
   \details GetContentsTableRop has fixed response size for:
   -# RowCount: uint32_t
 */
#define	SIZE_DFLT_ROPGETCONTENTSTABLE		4

/**
   \details GetPropertiesSpecificRop has fixed response size for:
   -# layout: uint8_t
 */
#define	SIZE_DFLT_ROPGETPROPERTIESSPECIFIC	1

/**
   \details SetColumnsRop has fixed response size for:
   -# TableStatus: uint8_t
 */
#define	SIZE_DFLT_ROPSETCOLUMNS			1

/**
   \details SortTableRop has fixed response size for:
   -# TableStatus: uint8_t
 */
#define	SIZE_DFLT_ROPSORTTABLE			1

/**
   \details QueryRowsRop has fixed size for:
   -# Origin: uint8_t
   -# RowCount: uint16_t
   -# RowData length: uint16_t
 */
#define	SIZE_DFLT_ROPQUERYROWS			5

/**
   \details SeekRowRop has fixed response size for:
   -# HasSought: uint8_t
   -# RowsSought: uint32_t
 */
#define	SIZE_DFLT_ROPSEEKROW			5

/**
   \details GetReceiveFolder has fixed response size for:
   -# folder_id: uint64_t
 */
#define	SIZE_DFLT_ROPGETRECEIVEFOLDER		8

/**
   \details LogonRop has a fixed size for mailbox:
   -# LogonFlags: uint8_t
   -# FolderIDs: uint64_t * 13
   -# ResponseFlags: uint8_t
   -# MailboxGUID: sizeof (struct GUID)
   -# ReplID: uint16_t
   -# ReplGUID: sizeof (struct GUID)
   -# LogonTime: uint8_t * 6 + uint16_t
   -# GwartTime: uint64_t
   -# StoreState: uint32_t
 */
#define	SIZE_DFLT_ROPLOGON_MAILBOX	160

#define	SIZE_NULL_TRANSACTION		2

__BEGIN_DECLS

/* definitions from libmapiserver_oxcfold.c */
uint16_t libmapiserver_RopOpenFolder_size(struct EcDoRpc_MAPI_REPL *);
uint16_t libmapiserver_RopGetContentsTable_size(struct EcDoRpc_MAPI_REPL *);

/* definitions from libmapiserver_oxcnotif.c */
uint16_t libmapiserver_RopRegisterNotification_size(void);

/* definitions from libmapiserver_oxcprpt.c */
uint16_t libmapiserver_RopGetPropertiesSpecific_size(struct EcDoRpc_MAPI_REQ *, struct EcDoRpc_MAPI_REPL *);
int libmapiserver_push_property(TALLOC_CTX *, struct smb_iconv_convenience *, uint32_t, const void *, DATA_BLOB *, uint8_t);

/* definitions from libmapiserver_oxcstor.c */
uint16_t libmapiserver_RopLogon_size(struct EcDoRpc_MAPI_REQ *, struct EcDoRpc_MAPI_REPL *);
uint16_t libmapiserver_RopRelease_size(void);
uint16_t libmapiserver_RopGetReceiveFolder_size(struct EcDoRpc_MAPI_REPL *);

/* definitions from libmapiserver_oxctabl.c */
uint16_t libmapiserver_RopSetColumns_size(struct EcDoRpc_MAPI_REPL *);
uint16_t libmapiserver_RopSortTable_size(struct EcDoRpc_MAPI_REPL *);
uint16_t libmapiserver_RopQueryRows_size(struct EcDoRpc_MAPI_REPL *);
uint16_t libmapiserver_RopSeekRow_size(struct EcDoRpc_MAPI_REPL *);

__END_DECLS

#endif /* ! __LIBMAPISERVER_H__ */
