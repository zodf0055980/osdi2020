#define BLOCK_SIZE 512
#define FAT32_ENTRY_PER_BLOCK (BLOCK_SIZE / sizeof(int))

void fat_getpartition();
void set_fat32_vnode(struct vnode *vnode);
int lookup_fat32(struct dentry *dir, struct vnode **target, char *component_name);
int create_fat32(struct dentry *dir, struct vnode **target, char *component_name);
int write_fat32(struct file *file, void *buf, unsigned long len);
int read_fat32(struct file *file, void *buf, unsigned long len);

// https://cpl.li/2019/mbrfat/
struct partition_entry
{
    unsigned char status;           //0x0
    unsigned char first_abs_sector; //0x1
    unsigned char partition_type;   //0x4
    unsigned char last_abs_sector;  //0x5
    unsigned int first_abs;         //0x8-0xB
    unsigned int number_sector;     //0xC-0xF

} partition_entry;

struct boot_sector
{
    unsigned char jump_instruction[3];                 // 0x0
    unsigned char oem_name[8];                         // 0x3
    unsigned short bytes_per_logical_sector;           // 0xB 0xC
    unsigned char logical_sector_per_cluster;          // 0xD
    unsigned short number_of_reserved_logical_sectors; // 0xE

    unsigned char number_of_file_alloc_tables; // 0x10
    unsigned short zero0;                      // 0x11-0x12
    unsigned short total_logical_sector;       // 0x13-0x14
    unsigned char media_descriptor;            // 0x15
    unsigned short zero1;                      // 0x16-0x17
    unsigned short physical_sectors_per_track; // 0x18-0x19
    unsigned short number_of_heads;            // 0x1A-0x1B
    unsigned int count_of_hidden_sectors;      // 0x1C-0x1F

    unsigned int total_logical_srctors;                // 0x20-0x23
    unsigned int logical_srctors_per_file_alloc_table; // 0x24-0x27
    unsigned short mirroring_flag;                     // 0x28-0x29
    unsigned short version;                            // 0x2A-0x2B
    unsigned int root_firector_cluster;                // 0x2C-0x2F

    unsigned short location_of_fs_info;       // 0x30-0x31
    unsigned short location_of_backup_sector; //0x32-0x33
    unsigned char reserved[12];               //0x34--0x3F

    unsigned char physical_dirve_num; // 0x40
    unsigned char flags;              //0x41
    unsigned char extend_signature;   //0x42

    unsigned int volume_serial_number; // 0x43-0x46
    unsigned char volume_lable[11];    // 0x47-0x51
    unsigned char file_system_type[8]; // 0x52-0x59
} boot_sector;

struct partition_entry *entry1;
struct boot_sector *sd_root_bst;

struct vnode_operations *fat32fs_v_ops;
struct file_operations *fat32fs_f_ops;