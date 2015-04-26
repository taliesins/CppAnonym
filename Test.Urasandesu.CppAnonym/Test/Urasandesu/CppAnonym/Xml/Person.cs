/// <remarks/>
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
[System.Xml.Serialization.XmlRootAttribute(Namespace = "", IsNullable = false)]
public partial class Person
{

    private byte ageField;

    private string nameField;

    private Arms armsField;

    private byte class_idField;

    private byte tracking_levelField;

    private byte versionField;

    /// <remarks/>
    public byte Age
    {
        get
        {
            return this.ageField;
        }
        set
        {
            this.ageField = value;
        }
    }

    /// <remarks/>
    public string Name
    {
        get
        {
            return this.nameField;
        }
        set
        {
            this.nameField = value;
        }
    }

    /// <remarks/>
    public Arms Arms
    {
        get
        {
            return this.armsField;
        }
        set
        {
            this.armsField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public byte class_id
    {
        get
        {
            return this.class_idField;
        }
        set
        {
            this.class_idField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public byte tracking_level
    {
        get
        {
            return this.tracking_levelField;
        }
        set
        {
            this.tracking_levelField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public byte version
    {
        get
        {
            return this.versionField;
        }
        set
        {
            this.versionField = value;
        }
    }
}

/// <remarks/>
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
public partial class Arms
{

    private byte countField;

    private byte item_versionField;

    private Arm[] itemField;

    private byte class_idField;

    private byte tracking_levelField;

    private byte versionField;

    /// <remarks/>
    public byte count
    {
        get
        {
            return this.countField;
        }
        set
        {
            this.countField = value;
        }
    }

    /// <remarks/>
    public byte item_version
    {
        get
        {
            return this.item_versionField;
        }
        set
        {
            this.item_versionField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("item")]
    public Arm[] item
    {
        get
        {
            return this.itemField;
        }
        set
        {
            this.itemField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public byte class_id
    {
        get
        {
            return this.class_idField;
        }
        set
        {
            this.class_idField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public byte tracking_level
    {
        get
        {
            return this.tracking_levelField;
        }
        set
        {
            this.tracking_levelField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public byte version
    {
        get
        {
            return this.versionField;
        }
        set
        {
            this.versionField = value;
        }
    }
}

/// <remarks/>
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType = true)]
public partial class Arm
{

    private string nameField;

    private byte class_idField;

    private byte tracking_levelField;

    private byte versionField;

    /// <remarks/>
    public string Name
    {
        get
        {
            return this.nameField;
        }
        set
        {
            this.nameField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public byte class_id
    {
        get
        {
            return this.class_idField;
        }
        set
        {
            this.class_idField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public byte tracking_level
    {
        get
        {
            return this.tracking_levelField;
        }
        set
        {
            this.tracking_levelField = value;
        }
    }

    /// <remarks/>
    [System.Xml.Serialization.XmlAttributeAttribute()]
    public byte version
    {
        get
        {
            return this.versionField;
        }
        set
        {
            this.versionField = value;
        }
    }
}
