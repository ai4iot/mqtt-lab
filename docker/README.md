
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

We have to navigate to the [mqtt directory](mqtt) and run the following
command:

```bash
docker compose up -d
```

This will download the mosquitto image and run it. The MQTT broker will be
listening on port 1883. To check that the MQTT broker is running, we can run
the following command:

```bash
docker ps
```







