def encrypt_file(encrypt_path, decrypt_path, key):
    with open(encrypt_path, "rb") as encrypt_file, open(decrypt_path, "wb") as decrypt_file:
        # 将key转化为字节码数据，并计算出所需要的字节长度
        key_bytes = key.to_bytes((key.bit_length() + 7) // 8, byteorder="big")
        key_len = len(key_bytes)
        # 将明文按所需字节长度读入缓冲区
        buffer = encrypt_file.read(key_len)
        # 循环缓冲区
        while buffer:
            encrypted_buffer = bytes([b ^ k for b, k in zip(buffer, key_bytes)])
            decrypt_file.write(encrypted_buffer)
            buffer = encrypt_file.read(key_len)

if __name__=="__main__":
    key = 20237690  
    # 加密
    encrypt_file("C:\Users\admin\Desktop\py智能车\encrypted.txt","C:\Users\admin\Desktop\py智能车\neuracecar_decrypted.txt", key)