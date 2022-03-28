-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : lun. 28 mars 2022 à 18:58
-- Version du serveur : 10.4.22-MariaDB
-- Version de PHP : 8.1.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `ceremonies`
--

-- --------------------------------------------------------

--
-- Structure de la table `ceremonie`
--

CREATE TABLE IF NOT EXISTS `ceremonie` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(100) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `chronogramme`
--

CREATE TABLE IF NOT EXISTS `chronogramme` (
  `idchronogramme` int(11) NOT NULL AUTO_INCREMENT,
  `heure` varchar(200) NOT NULL,
  `date` varchar(200) NOT NULL,
  `nom` varchar(200) NOT NULL,
  `idceremonie` int(11) NOT NULL,
  PRIMARY KEY (`idchronogramme`),
  KEY `idceremonie` (`idceremonie`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `invite`
--

CREATE TABLE IF NOT EXISTS `invite` (
  `id_invite` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(200) NOT NULL,
  `prenom` varchar(100) NOT NULL,
  `numero` varchar(200) NOT NULL,
  PRIMARY KEY (`id_invite`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `plats`
--

CREATE TABLE IF NOT EXISTS `plats` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `reservation`
--

CREATE TABLE IF NOT EXISTS `reservation` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `numerotable` int(11) NOT NULL,
  `numero_siege` int(11) NOT NULL,
  `idplat` int(11) NOT NULL,
  `idinvite` int(11) NOT NULL,
  `idceremonie` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `idceremonie` (`idceremonie`),
  KEY `reservation_ibfk_1` (`idinvite`),
  KEY `idplat` (`idplat`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `chronogramme`
--
ALTER TABLE `chronogramme`
  ADD CONSTRAINT `chronogramme_ibfk_1` FOREIGN KEY (`idceremonie`) REFERENCES `ceremonie` (`id`);

--
-- Contraintes pour la table `reservation`
--
ALTER TABLE `reservation`
  ADD CONSTRAINT `reservation_ibfk_1` FOREIGN KEY (`idplat`) REFERENCES `plats` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
