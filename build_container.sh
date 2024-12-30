#!/bin/sh

CONTAINER=$1
BUILD_PATH=../$2
DOCKERFILE=../$3

ARCH="linux/arm64"

FOLDER=$CONTAINER-$(date +%s)

mkdir $FOLDER
cd $FOLDER

echo $BUILD_PATH

CLEAN_ARCH=$(echo "$ARCH" | sed 's/[^a-zA-Z0-9]/-/g')
CONTAINER_WITH_ARCH="$CONTAINER-$CLEAN_ARCH"
    
echo "A construir imagem para $ARCH..."
    
docker build \
	--platform $ARCH \
        -f $DOCKERFILE \
        -t $CONTAINER_WITH_ARCH:latest \
	$BUILD_PATH
    
docker save $CONTAINER_WITH_ARCH | gzip > "$CONTAINER_WITH_ARCH.tar.gz"
    
echo "Imagem para $ARCH construída e guardada como $CONTAINER_WITH_ARCH.tar.gz"


cd ..
