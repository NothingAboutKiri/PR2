#ifndef TASK4_SHAMIR_FILE_H
#define TASK4_SHAMIR_FILE_H

void run_task4();
void encrypt_file_shamir(const char *input_path, const char *encrypted_path,
                         int p, int a, int b, int a_inverse);
void decrypt_file_shamir(const char *encrypted_path, const char *decrypted_path,
                         int p, int b_inverse);

#endif
