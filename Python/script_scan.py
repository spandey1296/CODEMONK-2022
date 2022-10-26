import os

print(
    """
auth
broadcast
brute
dos
malware
vuln
"""
)
scan_type = ["auth", "broadcast", "brute", "dos", "malware", "vuln"]
scan_type_choice = input("Enter type of scan: ").lower()

if scan_type_choice in scan_type:
    target_ip = input("Enter target ip: ")
    os.system(f"sudo nmap --script={scan_type_choice} {target_ip} -sS")
else:
    print("Invalid choice. Try again")
