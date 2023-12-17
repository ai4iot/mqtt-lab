
# Mosquitto MQTT Broker

## Install Docker
We are going to use Docker to run the MQTT broker.
If you don't have Docker installed, follow the
instructions [here](https://docs.docker.com/engine/install/).


### Install Docker Compose

We are going to use Docker Compose to run the MQTT broker.
If you don't have Docker Compose installed, follow the
instructions [here](https://docs.docker.com/compose/install/).

## Steps



We need to create some directories to store the configuration and data of the
MQTT broker. Choose a directory where you want to store the configuration and
data of the MQTT broker. In this example, we will use the directory
`~/mqtt`.

```bash
mkdir ~/mqtt
```
Then we need to create 3 subdirectories inside `~/mqtt`:

```bash
cd ~/mqtt
mkdir config data log
```

Now we can download the [docker-compose.yml](docker/docker-compose.yml) file
and copy it to the `~/mqtt` directory.

Then we enter into the `~/mqtt/config` directory and download the mosquitto.con file
and copy there. This file contains the configuration of the MQTT broker, such
as the port where it will be listening, the location of the data and log
directories and allows anonymous connections.

Finally, we enter into the `~/mqtt` directory and run the following command:

```bash
docker-compose up -d
```

This will download the mosquitto image and run it. The MQTT broker will be
listening on port 1883.






