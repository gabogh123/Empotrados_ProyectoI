import { useState } from 'react';
import { FlatList, Image, SafeAreaView, ScrollView, StyleSheet, Text, TouchableOpacity, View } from 'react-native';
import { Stack, useRouter } from 'expo-router';
import { COLORS, icons, images, SIZES } from '../../constants';

import SignInButton from '../SignInButton';

import axios from 'axios';

const PictureCard = ( {url} ) => {

    const [pictureUrl, setPictureUrl] = useState('https://i.imgur.com/7GAe73O.jpeg')

    const takePicture = async () => {

        const options = {
            method: 'POST',
            url: `${url}/picture`
        };

        try {
            const response = await axios.request(options);
            console.log('TOOK A PICTURE');
            console.log(response.data);

            // Regular expression to match <h1> and <p> tags
            const regex = /<h2>(.*?)<\/h2><p>(.*?)<\/p>/gs;

            // Array to store matched content
            const resultList = [];

            let match;
            while ((match = regex.exec(htmlData)) !== null) {
            const newPictureState = match[1]; // Content of <h2> tag
            const newPictureUrl = match[2]; // Content of <p> tag
            resultList.push({ controlElement, id,  state });
            }

            console.log(resultList);
            setPictureUrl(resultList.newPictureUrl);
        } catch (error) {
            console.error(error);
            alert('Picture could not be taken');
        }
    }

	return (
	
        <View style={styles.container}>
            <View style={styles.header}>
                <Text style={styles.headerTitle}>Picture</Text>
                <Text style={styles.headerInfo}>Click to watch your yard.</Text>
            </View>
            {/* Button */}
            <View style={styles.containerButton}>
                <SignInButton
                    buttonFunction={takePicture}
                    text={"Take Picture"}
                />
            </View>
            <Image
                source={{ uri: `${pictureUrl}` }}
                style={styles.image}
            />
        </View>
        
    
    );
};

const imgScl = 0.6;

const styles = StyleSheet.create({
    container: {
        marginTop: 10,
        marginBottom: 10
    },
    containerButton: {
        width: "100%",
        display: "flex",
        alignItems: "center",
        marginVertical: 30,
    },
    containerCards: {
        marginTop: SIZES.medium,
    },
    header: {
        // flexDirection: "collumn",
        width: "100%",
		backgroundColor: COLORS.white,
        // paddingLeft: 20,
        paddingVertical: 20
    },
    headerTitle: {
        fontSize: SIZES.xLarge,
        fontWeight: 'bold',
        color: COLORS.primary,
        marginBottom: 5,
      },
    headerInfo: {
        fontSize: SIZES.medium,
        color: COLORS.secondary,
      },
      image:
      {
        width: 640 * imgScl,
        height: 480 * imgScl,
        marginTop: 20
    }
});

export default PictureCard;
