
# Display OS version
os_version=$(cat /etc/os-release | grep PRETTY_NAME | cut -d'=' -f2 | tr -d '"')
echo "Operating System Version: $os_version"
# Display OS release number
os_release=$(cat /etc/os-release | grep VERSION_ID | cut -d'=' -f2 | tr -d '"')
echo "Release Number: $os_release"
# Display kernel version
kernel_version=$(uname -r)
echo "Kernel Version: $kernel_version"
