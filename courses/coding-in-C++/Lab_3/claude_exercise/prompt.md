# 🎮 Vereinfachtes Charaktersystem

## Kontext
Du baust ein kleines RPG-Charaktersystem. Es gibt verschiedene Charaktertypen, jeder kann eine Waffe tragen und ein Inventar besitzen.

---

## 📋 Anforderungen

### `Character` (Basisklasse)
- Name, Health Points (**private!**), Level (1–10)
- Methode `displayStatus()` — gibt Name, Typ, HP, Level aus
- Methode `levelUp()` — erhöht Level (max 10)

### `Warrior` erbt von Character
- Attribut: `weaponSkill` (int)
- Überschreibt `displayStatus()` um weaponSkill anzuzeigen

### `Mage` erbt von Character
- Attribut: `manaPoints` (int)
- Überschreibt `displayStatus()` um manaPoints anzuzeigen

### `Weapon` (eigenständige Klasse)
- Name, Schadenswert
- Jeder Character *kann* eine Weapon tragen (aber muss nicht)

### `Inventory` (eigenständige Klasse)
- Speichert bis zu 5 Item-Namen (`std::string`)
- Methoden: `addItem()`, `displayItems()`
- Jeder Character *besitzt genau eine* Inventory

---

## 🟡 Teil 1 – UML

Zeichne ein UML-Diagramm mit:
- Attributen + Sichtbarkeit
- Methoden
- Vererbung, Komposition, Assoziation
- Multiplizitäten

**Erkläre kurz** warum du Komposition vs. Assoziation gewählt hast.

---

## 🟡 Teil 2 – Implementierung

Implementiere die Klassen. Beantworte dabei:
- Warum bleiben Health Points `private`, obwohl Subklassen sie vielleicht brauchen?
- Wann würdest du `protected` statt `private` verwenden?

---

## 🟡 Teil 3 – Main

- Erstelle je einen `Warrior` und einen `Mage`
- Gib beiden eine Waffe und füge Items ins Inventar ein
- Rufe `displayStatus()` auf beiden auf
- Speichere beide in einem Array und gib das Level jedes Charakters aus