/*
 *  Common defines for cnid
 */

#ifndef _ATALK_CNID_PRIVATE_H
#define _ATALK_CNID_PRIVATE_H 1

#define CNID_DB_MAGIC   0x434E4944U  /* CNID */
#define CNID_DATA_MAGIC 0x434E4945U  /* CNIE */

#define CNID_OFS                 0
#define CNID_LEN                 4
 
#define CNID_DEV_OFS             CNID_LEN
#define CNID_DEV_LEN             8
 
#define CNID_INO_OFS             (CNID_DEV_OFS + CNID_DEV_LEN)
#define CNID_INO_LEN             8
 
#define CNID_DEVINO_OFS          CNID_LEN
#define CNID_DEVINO_LEN          (CNID_DEV_LEN +CNID_INO_LEN)
 
#define CNID_TYPE_OFS            (CNID_DEVINO_OFS +CNID_DEVINO_LEN)
#define CNID_TYPE_LEN            4
 
#define CNID_DID_OFS             (CNID_TYPE_OFS +CNID_TYPE_LEN)
#define CNID_DID_LEN             CNID_LEN
 
#define CNID_NAME_OFS            (CNID_DID_OFS + CNID_DID_LEN)
#define CNID_HEADER_LEN          (CNID_NAME_OFS)

#define CNIDFLAG_ROOTINFO_RO     (1 << 0)
#define CNIDFLAG_DB_RO           (1 << 1)

/* special key/data pair we use to store current cnid and database stamp in cnid2.db */

#define ROOTINFO_KEY    "\0\0\0\0"
#define ROOTINFO_KEYLEN 4

/* 
   Rootinfo data:
   4 unused bytes (cnid) 
   8 bytes, in first 4 bytes db stamp: struct stat.st_ctime of database file (dev)
   8 unused bytes (inode)
   4 bytes: is a file/directory (type)
   4 unused bytes (did)
   9 bytes name "RootInfo"
*/
#define ROOTINFO_DATA    "\0\0\0\0" \
                         "\0\0\0\0\0\0\0\0" \
                         "\0\0\0\0\0\0\0\0" \
                         "\0\0\0\0" \
                         "\0\0\0\0" \
                         "RootInfo"
#define ROOTINFO_DATALEN (3*4 + 2*8 + 9)

#endif
