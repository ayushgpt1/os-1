
# Display top 10 processes by CPU usage
echo "Top 10 processes by CPU usage:"
ps -eo pid,%cpu,%mem,cmd --sort=-%cpu | head -n 11

# Display processes with highest memory usage
echo "Processes with highest memory usage:"
ps -eo pid,%cpu,%mem,cmd --sort=-%mem | head -n 11
