#ifndef SYS_H
#define SYS_H

#include <unistd.h>

typedef ssize_t (*sys_write_t) (void *file, const void *buffer, size_t size);

typedef ssize_t (*sys_read_t) (void *file, void *buffer, size_t size);

typedef void *(*sys_open_t) (void *fs, const char *pathname, int flags);

typedef int (*sys_close_t) (void *file);

typedef off_t (*sys_lseek_t) (void *file, off_t offset, int whence);

typedef int (*sys_unlink_t) (void *fs, const char *pathname);

typedef int (*sys_rename_t) (void *fs, const char *oldpathname,
                             const char *newpathname);

/* Device operations.  */
typedef struct sys_devops_struct
{
    sys_write_t write;
    sys_read_t read;
    sys_open_t open;
    sys_close_t close;
    sys_lseek_t lseek;
} sys_devops_t;


typedef struct sys_fsops_struct
{
    /* Function to unlink (delete) a file.  */
    sys_unlink_t unlink;
    /* Function to rename a file.  */
    sys_rename_t rename;
    /* readdir ?  */
} sys_fsops_t;


/* Filesystem operations.  */
typedef struct sys_fs_struct
{
    /* Device operations.  */
    const sys_devops_t *devops;
    /* File system operations.  */
    const sys_fsops_t *fsops;
    /* Name of mount point.  */
    char mountname[8];
    /* The flags could be used for read-only.  */
    int flags;
    /* This is a handle for a file system implementation.  */
    void *private;
} sys_fs_t;


void sys_redirect_stdin (sys_read_t read, void *file);

void sys_redirect_stdout (sys_write_t write, void *file);

void sys_redirect_stderr (sys_write_t write, void *file);

bool sys_mount (sys_fs_t *fs, const char *mountname, int flags);

#endif
