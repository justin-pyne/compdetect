# CompDetect: End-to-End Network Compression Detection

This repository contains two related projects for detecting network compression:

- **Client/Server Application (Part I):**  
  A cooperative application where the client sends configuration information and two sets of UDP packet trains (one with low-entropy data and one with high-entropy data) to the server. The server measures the packet train arrival times to decide if compression is present.

- **Standalone Application (Part II):**  
  A non-cooperative application that uses raw sockets. It sends a head SYN, a train of UDP packets, and a tail SYN packet. The application listens for two RST responses and calculates the timing difference to detect compression.

## Project Overview

### Client/Server Application
- **Pre-Probing Phase:**  
  The client reads a configuration file (which includes parameters like server IP, UDP/TCP port numbers, payload size, etc.) and sends it via TCP to the server.

- **Probing Phase:**  
  The client sends two UDP packet trains:
  - **Low-Entropy Train:** UDP packets with payloads of zeros.
  - **High-Entropy Train:** UDP packets with payloads of random bits (using `/dev/urandom`).
  
  Each packet starts with a 16-bit packet ID.

- **Post-Probing Phase:**  
  After processing the received packets, the server computes the time differences between the first and last packets in each train. If the high-entropy train takes more than 100 ms longer than the low-entropy train, the server concludes that compression is present and sends the result back via TCP.

### Standalone Application
- Uses raw sockets to send:
  - A **head SYN** packet.
  - A UDP packet train.
  - A **tail SYN** packet.
- It listens for RST responses from the target. The time difference between the arrival of these RST packets is used to determine whether network compression is present.



