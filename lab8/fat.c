#include "sd.h"
#include "obj_alloc.h"
#include "uart.h"
#include "string.h"
#include "vfs.h"
#include "fat.h"

void fat_getpartition()
{
    printf("##### FAT32\n");
    unsigned char mbr[BLOCK_SIZE];
    readblock(0, mbr);

    entry1 = (struct partition_entry *)varied_size_alloc(sizeof(struct partition_entry));
    memcpy(entry1, mbr + 0x1BE, sizeof(struct partition_entry)); // 0x1BE 16	First partition table entry

    printf("##### first_abs: %x\n", entry1->first_abs);
    printf("##### numbe of sectors: %d\r\n", entry1->number_sector);

    unsigned char partition_block[BLOCK_SIZE];
    readblock(entry1->first_abs, partition_block);

    sd_root_bst = (struct boot_sector *)varied_size_alloc(sizeof(struct boot_sector));
    memcpy(sd_root_bst, partition_block, sizeof(struct boot_sector));
}

void set_fat32_vnode(struct vnode *vnode)
{
    // create root directory's vnode
    vnode->v_ops = fat32fs_v_ops;
    vnode->f_ops = fat32fs_f_ops;
}

int lookup_fat32(struct dentry *dir, struct vnode **target, char *component_name)
{
    return 0;
}

int create_fat32(struct dentry *dir, struct vnode **target, char *component_name)
{

    return 0;
}

int write_fat32(struct file *file, void *buf, unsigned long len)
{

    return 0;
}

int read_fat32(struct file *file, void *buf, unsigned long len)
{
    return 0;
}