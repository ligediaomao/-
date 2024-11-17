def decrypt_file(decrypt_path, encrypt_path, key):
    with open(decrypt_path, "rb") as decrypt_file, open(encrypt_path, "wb") as encrypt_file:
        key_bytes = key.to_bytes((key.bit_length() + 7) // 8, byteorder="big")
        key_len = len(key_bytes)
        buffer = decrypt_file.read(key_len)
        while buffer:
            decrypted_buffer = bytes([b ^ k for b, k in zip(buffer, key_bytes)])
            encrypt_file.write(decrypted_buffer)
            buffer = decrypt_file.read(key_len)
 
 
if __name__=="__main__":
    key = 123456  
    # 解密
    decrypt_file("C:\Users\admin\Desktop\py智能车\neuracecar_decrypted.txt","C:\Users\admin\Desktop\py智能车\encrypted.txt", key)