#ifndef SHAMIR_FILE_H
#define SHAMIR_FILE_H

void run_shamir_file();
void encrypt_file_shamir(const char *input_path, const char *encrypted_path,
                         int p, int a, int b, int a_inverse);
void decrypt_file_shamir(const char *encrypted_path, const char *decrypted_path,
                         int p, int b_inverse);

#endif
